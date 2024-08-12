/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:09:40 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/11 20:41:47 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	*routine(void *add)
{
	t_philo	*philo;
	t_table	*table;
	pthread_t	*mutex;

	philo = (t_philo *)add;
	table = philo->table;
	if (philo->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(mutex);
	while (!table->die && !table->eat_all)
	{
		is_eat(philo);
		ph_print(philo, SLEEP);
		ph_usleep(table, table->time_sleep);
		ph_print(philo, THINK);
	}
	pthread_mutex_unlock(mutex);
	return (NULL);
}
