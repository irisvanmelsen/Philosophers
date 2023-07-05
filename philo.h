/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:50:42 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/07/05 16:22:41 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>

typedef enum e_args {
	NUMBER = 1,
	DIE_TIME,
	EAT_TIME,
	SLEEP_TIME,
	EACH_TIME,
}	t_args;

typedef enum e_action {
	THINKING,
	DIED,
	SLEEPING,
	EATING,
	FORK,
}	t_action;

typedef enum e_error {
	ERROR_AMOUNT_ARGUMENTS,
	ERROR_INVALID_ARGUMENTS,
	ERROR_THREAD,
	ERROR_ALLOCATION,
}	t_error;

// nb_philo: number of philosophers and number of forks

// die_time: philo dies when they didn't start eating time_to_die
// milliseconds since the beginning of their last meal or simulation

// eat_time: time it takes for philo to eat while holding two forks

// sleep_time: time philosopher will spend sleeping

// each_time: if all philo have eaten at least number_of_times_each
// _philosopher_must_eat times, the simulation stops. If not specified
// the simulation stops when a philospher dies

typedef struct s_philo {
	int				philo_id;
	int				has_eaten;
	int				last_meal_time;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	int				philosophers;
	bool			stop_simulation;
	bool			philo_has_died;
	int				nb_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				each_time;
	int				start_time;
	int				philo_created;
	pthread_t		*philo_thread;
	pthread_mutex_t	simu_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	each_mutex;
	pthread_mutex_t	lock_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

// CHECK
bool		digit_check(int argc, char **argv);
bool		is_input_correct(int argc, char **argv);

// ERROR_AND_DESTROY
char		*get_error_name(t_error er);
bool		print_error(char *str);
void		destroy_all_muti(t_data *data, int count);

// INITIALISE
bool		initialisation(int argc, char **argv, t_data *data);
bool		init_mutex(t_data *data);
bool		fork_initialisation(t_data *data, int index);
int			allocate_philo_data(t_data *data);
bool		allocation(t_data *data);
bool		eat_initialisation(t_data *data, int index);

// INITIALISE_UTILS
size_t		philo_strlen(const char *s);
int			philo_atoi(const char *str);
void		*philo_calloc(size_t count, size_t size);
void		destroy_all_muti(t_data *data, int count);
bool		check_philo_atoi(t_data *data, char **argv);

// THREADS

void		*one_philo(t_philo *philo);
bool		philo_threads(t_data *data);
void		*routine(void *philosopher);
bool		monitoring(t_data *data);
int			thread_join(t_data *data);

// EAT
void		grab_forks(t_philo *philo);
bool		odd_philos(t_philo *philo);
bool		even_philos(t_philo *philo);
bool		eating(t_philo *philo);

// EAT UTILS
bool		right_fork(t_philo *philo);
bool		left_fork(t_philo *philo);
void		let_go_left_fork(t_philo *philo);
void		let_go_right_fork(t_philo *philo);
void		let_go_both_forks(t_philo *philo);

// TIME
int			get_time(void);
bool		thinking(t_philo *philo);
bool		died(t_philo *philo);
void		stop_simulation(t_philo *philo);
void		waiting(int wait_time);

// SLEEP
bool		custom_wait(int wait_time);
bool		sleeping(t_philo *philo);

// PRINT
const char	*actions(int action);
bool		print_action(t_philo *philo, int action);

#endif
