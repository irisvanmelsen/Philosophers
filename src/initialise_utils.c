/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:27:34 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/27 17:57:24 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// add overflow protection atoi

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

int	philo_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' && str[i] < '9')
			return (EXIT_FAILURE);
		result *= 10;
		result += str[i] - '0';
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

void	destroy_all_muti(t_data *data, int count)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->die_mutex);
	pthread_mutex_destroy(&data->each_mutex);
	pthread_mutex_destroy(&data->lock_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	while (i < count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}
