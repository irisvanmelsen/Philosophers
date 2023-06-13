/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:33:02 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/13 18:08:35 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// gettimeofday: gets the system's clock time
// the current time is expressed in elapsed seconds and microseconds
// since 00:00:00, January 1, 1970 (Unix Epoch)

// tv_sec is seconds
// tv_usec is microseconds
// tv is timeval (with tv_sec and tv_usec)
// tz is timezone

// 1 sec = hundred thousand (100 000) microseconds
// 1 sec = thousand (1000) milliseconds

int	get_milliseconds(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (EXIT_FAILURE);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
