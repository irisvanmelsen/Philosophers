/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:17:25 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/27 18:09:55 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// guess I need to add a check for when the philo is dead

int	sleeping(t_philo *philo)
{
	int	start_sleep;

	if (died(philo))
		return (EXIT_FAILURE);
	start_sleep = get_time();
	print_action(philo, SLEEPING);
	while (get_time() - start_sleep < philo->data->sleep_time)
		usleep(100);
	return (EXIT_SUCCESS);
}
