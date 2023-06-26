/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:51:07 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/26 17:53:02 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	let_go_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
}

void	let_go_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}
