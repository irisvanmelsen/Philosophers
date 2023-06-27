/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:43:25 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/27 18:37:12 by ivan-mel         ###   ########.fr       */
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
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
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

// int	test(t_data *data)
// {
// 	pthread_t	thread1;
// 	pthread_t	thread2;

// 	if (pthread_create(&thread1, NULL, mutex_lock_and_unlock, (void *)data))
// 	{
// 		destroy_mutex(data);
// 		return (print_error(get_error_name(ERROR_THREAD)));
// 	}
// 	if (pthread_create(&thread2, NULL, mutex_lock_and_unlock, (void *)data))
// 	{
// 		pthread_join(thread1, NULL);
// 		destroy_mutex(data);
// 		return (print_error(get_error_name(ERROR_THREAD)));
// 	}
// 	pthread_join(thread1, NULL);
// 	pthread_join(thread2, NULL);
// 	printf("num: %d\n", data->nb_philo);
// 	return (0);
// }
