/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:54:37 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/19 15:37:52 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	uneven_philos(t_data *data)
{
	usleep(data->eat_time / 2);
	mutex_lock_and_unlock(data->philos->right_fork);
}

void	even_philos(t_data *data)
{
	mutex_lock_and_unlock(data->philos->left_fork);
}

void	eating(t_data *data)
{
	int	start_time;

	start_time = get_time();
	while (get_time() - start_time < data->eat_time)
	{
		
	}
}
