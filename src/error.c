/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:23:33 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/05 18:00:51 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*get_error_name(t_error er)
{
	static char	*str[] = {
	[ERROR_ARGUMENTS] = "Invalid Amount of Arguments" \
	[ERROR_ARGUMENTS2] = "Invalid Argument"};

	return (str[er]);
}

int	print_error(char *str)
{
	write (STDERR_FILENO, str, philo_strlen(str));
	write (STDERR_FILENO, "\n", 2);
	return (EXIT_FAILURE);
}
