/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:33:02 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/05 16:50:53 by iris             ###   ########.fr       */
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
	pthread_mutex_lock(&philo->data->die_mutex);
	if (philo->data->philo_has_died == true)
		return (false);
	pthread_mutex_unlock(&philo->data->die_mutex);
	print_action(philo, THINKING);
	return (true);
}

void	waiting(int wait_time)
{
	int	start_time;

	start_time = get_time();
	while (get_time() - start_time < wait_time)
		usleep(100);
}

void	stop_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->simu_mutex);
	philo->data->stop_simulation = true;
	pthread_mutex_unlock(&philo->data->simu_mutex);
}

bool	died(t_philo *philo)
{
	int	last_mealtime;

	pthread_mutex_lock(&philo->eat_mutex);
	last_mealtime = philo->last_meal_time;
	pthread_mutex_unlock(&philo->eat_mutex);
	if (last_mealtime - philo->data->start_time > philo->data->die_time)
	{
		pthread_mutex_lock(&philo->data->die_mutex);
		philo->data->philo_has_died = true;
		stop_simulation(philo);
		pthread_mutex_unlock(&philo->data->die_mutex);
		print_action(philo, DIED);
		return (true);
	}
	return (false);
}
