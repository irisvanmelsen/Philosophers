/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:33:02 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/11 16:10:23 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// gettimeofday: gets the system's clock time
// the current time is expressed in elapsed seconds and microseconds
// since 00:00:00, January 1, 1970 (Unix Epoch)

// tv_sec is seconds
// tv_usec is microseconds
// tv is timeval (with tv_sec and tv_usec)
// tz is timezone

// 1 sec = hundred thousand (100 000) microseconds
// 1 sec = thousand (1000) milliseconds

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (EXIT_FAILURE);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	thinking(t_philo *philo)
{
	if (philo->data->max_amount_eating == true
		&& philo->data->nb_philo == philo->data->finished_eating + 1)
		return (false);
	pthread_mutex_lock(&philo->data->die_mutex);
	if (philo->data->philo_has_died == true)
		return (pthread_mutex_unlock(&philo->data->die_mutex), false);
	pthread_mutex_unlock(&philo->data->die_mutex);
	print_action(philo, THINKING);
	return (true);
}

bool	died(t_philo *philo)
{
	int	last_mealtime;

	if (philo->data->max_amount_eating == true
		&& philo->data->nb_philo == philo->data->finished_eating + 1)
		return (false);
	pthread_mutex_lock(&philo->eat_mutex);
	last_mealtime = philo->last_meal_time;
	pthread_mutex_unlock(&philo->eat_mutex);
	if (get_time() - last_mealtime >= philo->data->die_time)
	{
		pthread_mutex_lock(&philo->data->die_mutex);
		philo->data->philo_has_died = true;
		pthread_mutex_unlock(&philo->data->die_mutex);
		print_action(philo, DIED);
		return (true);
	}
	return (false);
}
