/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:22:11 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/20 18:24:00 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*actions(int action)
{
	static char	*str [] = {\
	[THINKING] = "is thinking",
	[SLEEPING] = "is sleeping",
	[EATING] = "is eating",
	[FORK] = "has taken a fork",
	[DIED] = "died"};

	return (str[action]);
}

char	print_action(t_data *data, t_philo philo, int action)
{
	int	time;

	time = data->start_time;
	printf("%d, %d", time, data->philos->philo_id);
	printf("%s", actions(action));
}
