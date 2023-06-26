/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:52:21 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/26 15:32:35 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	digit_check(int argc, char **argv)
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
			{
				printf("test2\n");
				return (EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	is_input_correct(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (print_error(get_error_name(ERROR_AMOUNT_ARGUMENTS)));
	if (digit_check(argc, argv))
		return (print_error(get_error_name(ERROR_INVALID_ARGUMENTS)));
	return (EXIT_SUCCESS);
}
