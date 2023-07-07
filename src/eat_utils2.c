/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:32:26 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/07 21:36:21 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	update_has_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	philo->has_eaten++;
	pthread_mutex_unlock(&philo->eat_mutex);
	// printf("%d\n", philo->has_eaten);
}
