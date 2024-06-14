/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:15:57 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/14 19:54:26 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_action
{
	int	num_philo;
	int	fork;
	int	time_eat;
	int	time_die;
	int	time_sleep;
}	t_action;

typedef struct s_philo
{
	struct philosopher	*next;
	t_action			action;
}	t_philo;

/*********************
 * PATH: SRCS/HANDLE *
 *********************/

int		handle_data(t_philo *data);
void	read_data(int argc, char *argv[], t_philo *philo);
int		handle_arg(int argc, char *argv[], t_philo *philo);

/********************
 * PATH: SRCS/UTILS *
 ********************/

void	ft_error(char *str, int status);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
