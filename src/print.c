/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:22:11 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/26 17:08:05 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*actions(int action)
{
	static char	*str [] = {\
	[THINKING] = "is thinking",
	[SLEEPING] = "is sleeping",
	[EATING] = "is eating",
	[FORK] = "has taken a fork",
	[DIED] = "died"};

	return (str[action]);
}

// maybe add bool function otherwise you are printing
// while they are already dead

char	print_action(t_philo *philos, int philo, int action)
{
	int	start;

	start = get_time();
	
	printf("%d, %d", time, philo);
	printf("%s\n", actions(action));
}
