/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:24:15 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/05 18:00:59 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_args(int argc, char *argv, t_data *data)
{
	t_data	*data;

	if (!argv[NUMBER] || !argv[DIE_TIME]
		|| !argv[EAT_TIME], !argv[EAT_TIME]
		|| !argv[SLEEP_TIME])
		return (print_error(get_error_name(ERROR_ARGUMENTS2)));
	data->nb = philo_atoi(argv[NUMBER]);
	data->die_time = philo_atoi(argv[DIE_TIME]);
	data->eat_time = philo_atoi(argv[EAT_TIME]);
	data->sleep_time = philo_atoi(argv[SLEEP_TIME]);
	if (argc == 6)
	{
		if (!argv[EACH_TIME])
			return (print_error(get_error_name(ERROR_ARGUMENTS2)));
		data->each_time = philo_atoi(argv[EACH_TIME]);
}