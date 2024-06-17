/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:15:57 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/17 14:42:59 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_philos;
	int				num_forks;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	int				times_eat;
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	death_mtx;
	long long		start_time;
	pthread_t		death_thr;
	int				all_eat;
}				t_philo;

typedef struct s_data
{
	t_philo		*philo_info;
	int			id;
	pthread_t	philo_thr;
	long long	state_time;
	long long	last_meal;
	int			times_eaten;
	long long	death_time;
}				t_data;


/*********************
 * PATH: SRCS/HANDLE *
 *********************/

/** File: handle_input.c */
int		handle_data(t_philo *data);
void	read_data(int argc, char *argv[], t_philo *philo);
int		handle_arg(int argc, char *argv[], t_philo *philo);

/********************
 * PATH: SRCS/UTILS *
 ********************/

/** File: utils_libft.c */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/** File: utils_philo.c */
void	ft_error(char *str, int status);
size_t	get_time(void);

#endif
