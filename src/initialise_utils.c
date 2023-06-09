/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:27:34 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/11 15:59:32 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	philo_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

bool	check_philo_atoi(t_data *data, char **argv)
{
	data->nb_philo = philo_atoi(argv[NUMBER]);
	if (data->nb_philo == -1)
		return (false);
	data->die_time = philo_atoi(argv[DIE_TIME]);
	if (data->die_time == -1)
		return (false);
	data->eat_time = philo_atoi(argv[EAT_TIME]);
	if (data->eat_time == -1)
		return (false);
	data->sleep_time = philo_atoi(argv[SLEEP_TIME]);
	if (data->sleep_time == -1)
		return (false);
	return (true);
}

int	philo_atoi(const char *str)
{
	int				i;
	unsigned int	result;
	unsigned int	prev_res;

	i = 0;
	result = 0;
	while (str[i])
	{
		prev_res = result;
		if (str[i] == '-')
			return (-1);
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result *= 10;
		result += str[i] - '0';
		if (result < prev_res)
			return (-1);
		i++;
	}
	return (result);
}

void	*philo_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	i = 0;
	if (ptr == NULL)
		return (ptr);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

bool	allocation(t_data *data)
{
	int	i;

	i = 0;
	if (allocate_philo_data(data))
		return (EXIT_FAILURE);
	while (i < data->nb_philo)
	{
		data->philos[i].data = data;
		data->philos[i].philo_id = i + 1;
		data->philos[i].left_fork = NULL;
		data->philos[i].right_fork = NULL;
		data->philos[i].has_eaten = 0;
		if (fork_initialisation(data, data->philos[i].philo_id - 1) == false)
		{
			destroy_all_muti(data, i);
			return (false);
		}
		if (eat_initialisation(data, data->philos[i].philo_id - 1) == false)
		{
			destroy_all_muti(data, i);
			return (false);
		}
		i++;
	}
	return (true);
}
