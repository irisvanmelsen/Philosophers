/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:06:42 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/11 16:17:41 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	eat_monitoring(t_data *data, int i)
{
	if (data->philos->data->max_amount_eating == true
		&& data->nb_philo == data->finished_eating + 1)
		return (false);
	if (data->max_amount_eating == true
		&& data->nb_philo == data->finished_eating + 1)
	{
		pthread_mutex_lock(&data->die_mutex);
		data->philo_has_died = true;
		pthread_mutex_unlock(&data->die_mutex);
		return (false);
	}
	if (data->max_amount_eating == true)
	{
		pthread_mutex_lock(&data->philos->eat_mutex);
		if (data->philos[i].has_eaten >= data->each_time)
			data->finished_eating++;
		pthread_mutex_unlock(&data->philos->eat_mutex);
	}
	return (true);
}
