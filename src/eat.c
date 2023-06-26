/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:54:37 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/26 17:57:38 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	grab_forks(t_data *data)
{
	if (data->nb_philo % 2)
		odd_philos(data->philos);
	else
		even_philos(data->philos);
}

void	odd_philos(t_philo *philo)
{
	right_fork(philo);
	left_fork(philo);
}

void	even_philos(t_philo *philo)
{
	left_fork(philo);
	right_fork(philo);
}

void	right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, philo->philo_id, FORK);
}

void	left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, philo->philo_id, FORK);
}

void	eating(t_philo *philo)
{
	int	start_time;
	
	start_time == get_time();
	print_action(philo->data, philo->philo_id, EATING);
	philo->has_eaten++;
	while (get_time() - start_time < philo->data->eat_time)
	{

	}s
}
