/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:50:42 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/05 17:58:17 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef enum e_args {
	NUMBER = 1,
	DIE_TIME,
	EAT_TIME,
	SLEEP_TIME,
	EACH_TIME,
}	t_args;

typedef enum e_error {
	ERROR_ARGUMENTS,
	ERROR_ARGUMENTS2,
}	t_error;

typedef struct s_data {
	int	nb;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	each_time;
}	t_data;

// ERROR
char	*get_error_name(t_error er);
int		print_error(char *str);

// PARSING_UTILS
size_t	philo_strlen(const char *s);
int		philo_atoi(const char *str);

// INITIALISE
int		init_args(int argc, char *argv, t_data *data);

#endif
