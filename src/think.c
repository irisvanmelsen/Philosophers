/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:08:52 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/26 17:13:11 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	thinking(t_philo *philo)
{
	if (philo->alive == DIED)
		return (EXIT_FAILURE);
	print_action(philo->data, philo, THINKING);
	return (EXIT_SUCCESS);
}
