/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:18:37 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/29 15:48:36 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (is_input_correct(argc, argv) == false)
		return (EXIT_FAILURE);
	if (initialisation(argc, argv, &data) == false)
		return (EXIT_FAILURE);
	philo_threads(&data);
	monitoring(&data);
	thread_join(&data);
	return (EXIT_SUCCESS);
}
