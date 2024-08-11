/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:15:57 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/07 15:07:09 by jikarunw         ###   ########.fr       */
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

enum	e_state
{
	FORK = 0,
	EAT,
	THINK,
	SLEEP,
	DEAD
};

typedef struct s_philo
{
	int				id;
	int				meal_eat;
	size_t			last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*r_fork;
	struct s_philo	*l_fork;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				num_philo;
	int				eat_all;
	int				die;
	size_t			table_init;
	t_philo			*philo;
	pthread_mutex_t	is_print;
	pthread_mutex_t	is_check;
}	t_table;


/************************
 * PATH: SRCS/ALGORITHM *
 ************************/

/** File: Monitor.c */
// void	monitor(t_data *data);

/** File: routine.c */
void	*routine(void *add);
void	is_eat(t_philo *philo);
void	is_die(t_table *table);

/** File: init_philo.c */
void	is_eat(t_philo *philo);
void	is_die(t_table *table);

/*********************
 * PATH: SRCS/HANDLE *
 *********************/

/** File: handle_input.c */
int	handle_arg(int argc, char *argv[], t_table *table);

/********************
 * PATH: SRCS/UTILS *
 ********************/

/** File: utils_libft.c */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
size_t	ft_strlen(char *str);

/** File: utils_philo.c */
void	ph_exit(t_table *table, pthread_t *thread);
size_t	get_curr_time(void);
void	ph_usleep(t_table *table, size_t time_sleep);
void	ph_print(t_philo *philo, int msg);

#endif
