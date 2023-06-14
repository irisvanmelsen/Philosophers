/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:08:48 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/14 10:16:08 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int pthread_mutex_init(pthread_mutex_t *mutex,
// const pthread_mutex, attr_t *attr);

// pthread_mutex_init: initialise the mutex with attributes specified
// by attr
// if attr is NULL then default attributes are used
// upon successful initionalisation, the state of mutex
// becomes initialised and unlocked

void	*mutex_lock_and_unlock(void *arg)
{
	int		i;
	int		nb_philo;
	t_data	*data;

	data = (t_data *)arg;
	i = 0;
	while (i < 100)
	{
		pthread_mutex_lock(&data->die_mutex);
		nb_philo = data->nb_philo++;
		pthread_mutex_unlock(&data->die_mutex);
		i++;
	}
	return (NULL);
}

void	destroy_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->die_mutex);
	free(data);
}
