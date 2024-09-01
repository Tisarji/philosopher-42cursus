/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:19:59 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/29 05:06:11 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	handle_arg(t_table *table, int ac, char **av)
{
	if (5 > ac || ac > 6)
		return (1);
	table->num_philo = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (table->num_philo <= 0 || table->time_die <= 0
		|| table->time_eat <= 0 || table->time_sleep <= 0)
		return (1);
	if (ac == 6)
	{
		table->must_time_eat = ft_atoi(av[5]);
		if (table->must_time_eat <= 0)
			return (1);
	}
	else
		table->must_time_eat = -1;
	return (0);
}
