/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:23:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/05 16:13:12 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*get_error_name(t_error er)
{
	static char	*str[] = {
	[ERROR_AMOUNT_ARGUMENTS] = "Invalid Amount of Arguments", \
	[ERROR_INVALID_ARGUMENTS] = "Invalid Argument", \
	[ERROR_THREAD] = "Thread Creation Failure", \
	[ERROR_ALLOCATION] = "Allocation Failure"};

	return (str[er]);
}

bool	print_error(char *str)
{
	write (STDERR_FILENO, str, philo_strlen(str));
	write (STDERR_FILENO, "\n", 2);
	return (false);
}

void	destroy_all_muti(t_data *data, int count)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->die_mutex);
	pthread_mutex_destroy(&data->each_mutex);
	pthread_mutex_destroy(&data->lock_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->simu_mutex);
	while (i < count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}
