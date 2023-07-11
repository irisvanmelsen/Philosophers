/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:32:26 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/11 15:59:15 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	update_has_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	philo->has_eaten++;
	pthread_mutex_unlock(&philo->eat_mutex);
}
