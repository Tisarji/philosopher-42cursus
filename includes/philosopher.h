/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:15:57 by jikarunw          #+#    #+#             */
/*   Updated: 2024/05/13 17:06:12 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

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

#endif
