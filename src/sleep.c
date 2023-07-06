/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:17:25 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/06 16:28:58 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	custom_wait(t_philo *philo, int wait_time)
{
	int	start_sleep;

	start_sleep = get_time();
	while (get_time() - start_sleep < wait_time)
	{
		pthread_mutex_lock(&philo->data->die_mutex);
		if (philo->data->philo_has_died == true)
			return (pthread_mutex_unlock(&philo->data->die_mutex), false);
		pthread_mutex_unlock(&philo->data->die_mutex);
		usleep(250);
		// printf("test123\n");
	}
	return (true);
}

bool	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die_mutex);
	if (philo->data->philo_has_died == true)
		return (pthread_mutex_unlock(&philo->data->die_mutex), false);
	pthread_mutex_unlock(&philo->data->die_mutex);
	print_action(philo, SLEEPING);
	return (custom_wait(philo, philo->data->sleep_time));
}
