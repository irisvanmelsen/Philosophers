/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:52:21 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/11 15:59:10 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	digit_check(int argc, char **argv)
{
	int	y;
	int	x;

	y = 1;
	if (argv[1][0] == '0')
		return (false);
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
