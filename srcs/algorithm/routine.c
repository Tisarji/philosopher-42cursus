/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:09:40 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/24 14:11:41 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	*routine(void *add)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)add;
	table = philo->table;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!table->die && !table->eat_all)
	{
		is_eat(philo);
		ph_print(philo, SLEEP);
		ph_usleep(table, table->time_sleep);
		ph_print(philo, THINK);
	}
	return (NULL);
}
