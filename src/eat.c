/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:54:37 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/05 13:32:24 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	grab_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		even_philos(philo);
	else
		odd_philos(philo);
}

bool	odd_philos(t_philo *philo)
{
	if (left_fork(philo))
	{
		if (right_fork(philo))
			return (true);
		else
		{
			let_go_left_fork(philo);
			return (false);
		}
	}
	return (false);
}

bool	even_philos(t_philo *philo)
{
	if (right_fork(philo))
	{
		if (left_fork(philo))
			return (true);
		else
		{
			let_go_right_fork(philo);
			return (false);
		}
	}
	return (false);
}

bool	eating(t_philo *philo)
{
	grab_forks(philo);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	if (print_action(philo, EATING) == false)
	{
		let_go_both_forks(philo);
		return (false);
	}
	philo->has_eaten++;
	custom_wait(philo->data->eat_time);
	let_go_both_forks(philo);
	return (true);
}
