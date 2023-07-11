/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:51:07 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/11 15:59:14 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (print_action(philo, FORK) == false)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (false);
	}
	return (true);
}

bool	left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (print_action(philo, FORK) == false)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (false);
	}
	return (true);
}

void	let_go_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
}

void	let_go_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}

void	let_go_both_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
