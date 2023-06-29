/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:17:25 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/29 15:39:30 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	sleeping(t_philo *philo)
{
	int	start_sleep;

	if (philo->data->philo_has_died == true)
		return (false);
	start_sleep = get_time();
	print_action(philo, SLEEPING);
	while (get_time() - start_sleep < philo->data->sleep_time)
		usleep(250);
	return (true);
}
