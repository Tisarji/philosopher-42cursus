/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:15:57 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/01 23:00:31 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define BLACK "\e[1;30m"
# define GREEN "\e[1;32m"
# define RED "\e[1;31m"
# define WHITE "\e[1;37m"
# define YELLOW "\e[1;33m"
# define CYAN "\e[1;36m"
# define PURPLE "\e[1;35m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_table {
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_time_eat;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	count_mutex;
	suseconds_t		start_milliseconds;
	int				start;
	int				count_remain;
}	t_table;

typedef struct s_philo {
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	last_eat_mutex;
	t_table			*table;
	int				id;
	int				last_eat;
	pthread_t		thread;
}	t_philo;

/************************
 * PATH: SRCS/ALGORITHM *
 ************************/

/** File: routine.c */
void		*routine(t_philo *philo);

/** File: init_philo.c */
t_philo		*init_philos(t_table *table);

/** File: monitor.c */
void		monitor_philosophers(t_philo *philo);
int			start_simulation(t_philo *philo);

/** File: handle_input.c */
int			handle_arg(t_table *table, int ac, char **av);

/** File: ph_eat.c */
int			ph_eat(t_philo *philo, int *eat_count);

/*******************
 * PATH:SRCS/UTILS *
 *******************/

/** File: utils_libft.c */
size_t		ft_strlen(char *str);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t num);

/** File: utils_philo.c */
int			ph_action(t_philo *philo, const char *action);
suseconds_t	ph_get_timestamp(suseconds_t millisecond);
void		ph_msleep(int msec);

/** File: utils_setup.c */
void		ph_setting(pthread_mutex_t *mutex, int *value, int next);
int			ph_getting(pthread_mutex_t *mutex, int *value);

/** File: utils_destroy.c */
void		ph_destroy(t_table *table);
void		ph_resources_destroy(t_philo *philo, int num, bool thread);
void		ph_cleanup(t_philo *philo);

#endif
