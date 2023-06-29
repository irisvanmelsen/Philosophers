/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:43:25 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/29 15:41:21 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int pthread_create((pthread_t *thread, const pthread_attr_t *attr,
// void *(*start_routine) (void *), void *arg);)

// pthread_create: used to create new thread that starts executing the
// start_routine function
// the newly created thread runs concurrently with the main thread

// thread: will hold thread ID of newly created thread
// atr: pointer to attribute, if NULL is passed default attributes are used
// start_routine: pointer to function that will be executed by new thread
// this function should take a void* and returns void* pointer
// arg: optional arg that can be passed to start_routine function
// this arg is of type void* so it can pass data do thread function

// lock and unlock is done so they all go eat at the same time

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	pthread_mutex_lock(&philo->data->lock_mutex);
	pthread_mutex_unlock(&philo->data->lock_mutex);
	if (philo->data->philo_created != philo->data->nb_philo)
		return (0);
	while (1)
	{
		if (eating(philo) == false)
			break ;
		if (sleeping(philo) == false)
			break ;
		if (thinking(philo) == false)
			break ;
	}
	return (EXIT_SUCCESS);
}

bool	monitoring(t_data *data)
{
	int	i;

	usleep(250);
	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (died(&data->philos[i]) == true)
				return (false);
			i++;
		}
		usleep(250);
	}
	return (true);
}

bool	philo_threads(t_data *data)
{
	int	i;

	i = 0;
	data->philo_created = 0;
	pthread_mutex_lock(&data->lock_mutex);
	printf("nb_philo: %d\n", data->nb_philo);
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo_thread[i], NULL, &routine,
				&data->philos[i]) != 0)
		{
			pthread_mutex_unlock(&data->lock_mutex);
			return (false);
		}
		data->philo_created++;
		i++;
	}
	data->start_time = get_time();
	pthread_mutex_unlock(&data->lock_mutex);
	return (true);
}

int	thread_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo_thread[i], NULL))
		{
			destroy_all_muti(data, data->nb_philo);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
