/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:24:15 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/20 18:12:17 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	initialisation(int argc, char **argv, t_data *data)
{
	if (!argv[NUMBER] || !argv[DIE_TIME]
		|| !argv[EAT_TIME] || !argv[EAT_TIME]
		|| !argv[SLEEP_TIME])
		return (print_error(get_error_name(ERROR_ARGUMENTS2)));
	data->nb_philo = philo_atoi(argv[NUMBER]);
	data->die_time = philo_atoi(argv[DIE_TIME]);
	data->eat_time = philo_atoi(argv[EAT_TIME]);
	data->sleep_time = philo_atoi(argv[SLEEP_TIME]);
	if (argc == 6)
	{
		if (!argv[EACH_TIME])
			return (print_error(get_error_name(ERROR_ARGUMENTS2)));
		data->each_time = philo_atoi(argv[EACH_TIME]);
	}
	if (philo_allocation(data))
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	return (EXIT_SUCCESS);
}

t_data	*init_mutex(t_data *data)
{
	pthread_mutex_init(&data->die_mutex, NULL);
	pthread_mutex_init(&data->each_mutex, NULL);
	return (data);
}

void	fork_initialisation(t_data *data, int index)
{
	data->philos[index].left_fork = &data->forks[index];
	if ((index + 1) == data->nb_philo)
		data->philos[index].right_fork = &data->forks[0];
	else
		data->philos[index].right_fork = &data->forks[index + 1];
	return ;
}

int	philo_allocation(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = philo_calloc(sizeof (t_philo), data->nb_philo);
	if (!philos)
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	data->philos = philos;
	data->forks = philo_calloc(sizeof (pthread_mutex_t), data->nb_philo);
	if (!data->forks)
	{
		free(data->philos);
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	}
	while (i < data->nb_philo)
	{
		philos[i].data = data;
		philos[i].philo_id = i + 1;
		philos[i].has_eaten = 0;
		philos[i].left_fork = NULL;
		philos[i].right_fork = NULL;
		fork_initialisation(data, philos[i].philo_id - 1);
		printf("philo_id: %d\n", philos[i].philo_id);
		printf("forks right: %p\n", philos[i].right_fork);
		printf("fork left: %p\n", philos[i].left_fork);
		i++;
	}
	return (EXIT_SUCCESS);
}
