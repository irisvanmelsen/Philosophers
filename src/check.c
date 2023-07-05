/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:52:21 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/05 13:55:09 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// make function that checks if values are correct / make sense

bool	digit_check(int argc, char **argv)
{
	int	y;
	int	x;

	y = 1;
	while (y < argc)
	{
		x = 0;
		while (argv[y][x])
		{
			if (argv[y][x] < '0' || argv[y][x] > '9')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	is_input_correct(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (print_error(get_error_name(ERROR_AMOUNT_ARGUMENTS)));
	if (digit_check(argc, argv) == false)
		return (print_error(get_error_name(ERROR_INVALID_ARGUMENTS)));
	return (true);
}
