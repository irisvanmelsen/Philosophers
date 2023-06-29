/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:24:15 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/29 14:48:08 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	initialisation(int argc, char **argv, t_data *data)
{
	if (!argv[NUMBER] || !argv[DIE_TIME]
		|| !argv[EAT_TIME] || !argv[EAT_TIME]
		|| !argv[SLEEP_TIME])
		return (print_error(get_error_name(ERROR_INVALID_ARGUMENTS)));
	if (check_philo_atoi(data, argv) == false)
		return (false);
	if (argc == 6)
	{
		if (!argv[EACH_TIME])
			return (print_error(get_error_name(ERROR_INVALID_ARGUMENTS)));
		data->each_time = philo_atoi(argv[EACH_TIME]);
		if (!data->each_time)
			return (false);
	}
	data->philo_has_died = false;
	init_mutex(data);
	if (!allocation(data))
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	return (true);
}

// initialise eat mutex for each philo

bool	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->die_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->each_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->die_mutex);
		return (false);
	}
	if (pthread_mutex_init(&data->lock_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->die_mutex);
		pthread_mutex_destroy(&data->each_mutex);
		return (false);
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->die_mutex);
		pthread_mutex_destroy(&data->each_mutex);
		pthread_mutex_destroy(&data->lock_mutex);
		return (false);
	}
	return (true);
}

bool	eat_initialisation(t_data *data, int index)
{
	if (pthread_mutex_init(&data->philos[index].eat_mutex, NULL) != 0)
		return (false);
	return (true);
}

bool	fork_initialisation(t_data *data, int index)
{
	if (pthread_mutex_init(&data->forks[index], NULL) != 0)
		return (false);
	data->philos[index].left_fork = &data->forks[index];
	if ((index + 1) == data->nb_philo)
		data->philos[index].right_fork = &data->forks[0];
	else
		data->philos[index].right_fork = &data->forks[index + 1];
	return (true);
}

int	allocate_philo_data(t_data *data)
{
	data->philos = philo_calloc(sizeof (t_philo), data->nb_philo);
	if (!data->philos)
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	data->forks = philo_calloc(sizeof (pthread_mutex_t), data->nb_philo);
	if (!data->forks)
	{
		free(data->philos);
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	}
	data->philo_thread = philo_calloc(sizeof (pthread_t), data->nb_philo);
	if (!data->philo_thread)
	{
		free(data->philos);
		free(data->forks);
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	}
	return (EXIT_SUCCESS);
}

bool	allocation(t_data *data)
{
	int	i;

	i = 0;
	if (allocate_philo_data(data))
		return (EXIT_FAILURE);
	while (i < data->nb_philo)
	{
		data->philos[i].data = data;
		data->philos[i].philo_id = i + 1;
		data->philos[i].left_fork = NULL;
		data->philos[i].right_fork = NULL;
		data->philos[i].has_eaten = 0;
		if (fork_initialisation(data, data->philos[i].philo_id - 1) == false)
		{
			destroy_all_muti(data, i);
			return (false);
		}
		if (eat_initialisation(data, data->philos[i].philo_id - 1) == false)
		{
			destroy_all_muti(data, i);
			return (false);
		}
		// printf("philo_id: %d\n", data->philos[i].philo_id);
		// printf("forks right: %p\n", data->philos[i].right_fork);
		// printf("fork left: %p\n", data->philos[i].left_fork);
		// printf("%p\n", &data->philos[i].eat_mutex);
		i++;
	}
	return (true);
}
