/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:54:37 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/20 18:12:08 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	right_fork(t_data *data)
{
	mutex_lock_and_unlock(data->philos->right_fork);
}

void	left_fork(t_data *data)
{
	mutex_lock_and_unlock(data->philos->left_fork);
}

void	eating(t_data *data)
{
	int	start_time;

	start_time == get_time();
	print_action(data, EATING);
	data->philos->has_eaten++;
	while (get_time() - start_time < data->eat_time)
	{

	}
}
