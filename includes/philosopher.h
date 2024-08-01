/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:15:57 by jikarunw          #+#    #+#             */
/*   Updated: 2024/07/18 18:47:53 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define WHITE "\e[0;37m"
# define YELLOW "\e[0;33m"
# define CYAN "\e[0;36m"
# define PURPLE "\e[0;35m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_data
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	pthread_mutex_t		monitor;
	pthread_mutex_t		eat;
	int					dead;
	int					num_philo;
	int					time_eat;
	int					time_die;
	int					time_sleep;
	time_t				time_start;
	int					time_must_eat;
	int					eat_verify;
	struct s_philo		*philo;
}				t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long			last_spaghetti;
	int				left_fork;
	int				right_fork;
	int				num_eat;
	t_data			*data;
}				t_philo;

enum	e_state
{
	FORK,
	EAT,
	THINK,
	SLEEP,
	DEAD
};

/************************
 * PATH: SRCS/ALGORITHM *
 ************************/

/** File: Monitor.c */
void	monitor(t_data *data);

/** File: routine.c */
void	*routine(void *add);
void	is_eat(t_philo *philo, int id);
/** File: init_data.c */
void	is_eat(t_philo *philo, int id);
void	init_fork(t_data *data);
int		init_philo(t_data *data);

/*********************
 * PATH: SRCS/HANDLE *
 *********************/

/** File: handle_input.c */
int		valid_arg(int argc, char *argv[]);
int		handle_arg(int argc, char *argv[], t_data *data);

/********************
 * PATH: SRCS/UTILS *
 ********************/

/** File: utils_libft.c */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/** File: utils_philo.c */
void	ph_exit(t_data *data);
void	ph_print(int id, t_data *data, int mode);
void	ph_sleep(t_data *data, time_t finish);
time_t	get_curr_time(t_data *data);

#endif
