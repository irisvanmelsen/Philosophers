/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:43:25 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/20 17:39:00 by ivan-mel         ###   ########.fr       */
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

int	threads(t_data *data)
{
	data->start_time = get_time();
	if (data->nb_philo % 2)
		odd_philos(data->philos);
	else
		even_philos(data->philos);
}

void	odd_philos(t_data *data)
{
	usleep(data->eat_time / 2);
}

void	even_philos(t_data *data)
{
	left_fork();
	right_fork();
}

int	test(t_data *data)
{
	pthread_t	thread1;
	pthread_t	thread2;

	if (pthread_create(&thread1, NULL, mutex_lock_and_unlock, (void *)data))
	{
		destroy_mutex(data);
		return (print_error(get_error_name(ERROR_THREAD)));
	}
	if (pthread_create(&thread2, NULL, mutex_lock_and_unlock, (void *)data))
	{
		pthread_join(thread1, NULL);
		destroy_mutex(data);
		return (print_error(get_error_name(ERROR_THREAD)));
	}
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("num: %d\n", data->nb_philo);
	return (0);
}
