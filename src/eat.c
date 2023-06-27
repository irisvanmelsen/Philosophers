/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:54:37 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/27 19:00:52 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	grab_forks(t_philo *philo)
{
	if (philo->data->nb_philo % 2)
		odd_philos(philo->data->philos);
	else
		even_philos(philo->data->philos);
}

bool	odd_philos(t_philo *philo)
{
	if (right_fork(philo))
		return (false);
	if (left_fork(philo))
	{
		let_go_right_fork(philo);
		return (false);
	}
	return (true);
}

bool	even_philos(t_philo *philo)
{
	if (left_fork(philo))
		return (false);
	if (right_fork(philo))
	{
		let_go_left_fork(philo);
		return (false);
	}
	return (true);
}

bool	eating(t_philo *philo)
{
	grab_forks(philo);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	if (print_action(philo, EATING) == false)
		return (false);
	philo->has_eaten++;
	return (true);
}
