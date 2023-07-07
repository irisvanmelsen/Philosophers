/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:22:11 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/07 22:18:15 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// perhaps both functions could become one

static bool	has_philo_died(t_philo *philo)
{
	bool	state;

	pthread_mutex_lock(&philo->data->die_mutex);
	state = philo->data->philo_has_died;
	pthread_mutex_unlock(&philo->data->die_mutex);
	return (state);
}

const char	*actions(int action)
{
	static const char	*str [] = {\
	[THINKING] = "is thinking",
	[SLEEPING] = "is sleeping",
	[EATING] = "is eating",
	[FORK] = "has taken a fork",
	[DIED] = "died"};

	return (str[action]);
}

bool	print_action(t_philo *philo, int action)
{
	if (action != DIED && has_philo_died(philo) == true)
		return (false);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%d %d %s\n", get_time() - philo->data->start_time, philo->philo_id,
		actions(action));
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (true);
}
