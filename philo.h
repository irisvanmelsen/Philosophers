/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:50:42 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/06/13 17:29:25 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

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
	ERROR_THREAD,
}	t_error;

// nb_philo: number of philosophers and number of forks

// die_time: philo dies when they didn't start eating time_to_die
// milliseconds since the beginning of their last meal or simulation

// eat_time: time it takes for philo to eat while holding two forks

// sleep_time: time philosopher will spend sleeping

// each_time: if all philo have eaten at least number_of_times_each
// _philosopher_must_eat times, the simulation stops. If not specified
// the simulation stops when a philospher dies
typedef struct philo {
	// last meal
	// life
	int				philo_id;
	int				fork;
	pthread_mutex_t	fork_mutex;
}	t_philo;

typedef struct s_data {
	// start time
	int				nb;
	int				nb_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				each_time;
	pthread_t		*philo_thread;
	pthread_mutex_t	die_mutex;
	// pthread_mutex_t	eat_mutex;
	// pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	each_mutex;
	t_philo			**philos;
}	t_data;

// ERROR
char	*get_error_name(t_error er);
int		print_error(char *str);

// INITIALISE
int		init_args(int argc, char **argv, t_data *data);
t_data	*init_mutex(t_data *data);

// INITIALISE_UTILS
size_t	philo_strlen(const char *s);
int		philo_atoi(const char *str);

// THREADS

int		test(t_data *data);

// MUTEX
void	*mutex_lock_and_unlock(void *arg);
void	destroy_mutex(t_data *data);

#endif
