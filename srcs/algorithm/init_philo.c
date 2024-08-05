/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:11:30 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/05 20:27:14 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	is_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&philo->fork);
	ph_print(philo, FORK);
	if (philo->table->num_philo == 1)
	{
		ph_usleep(table, table->die);
		ph_print(philo, DEAD);
		pthread_mutex_unlock(&philo->fork);
		table->die = 1;
		return ;
	}
	pthread_mutex_lock(&philo->r_fork->fork);
	ph_print(philo, FORK);
	pthread_mutex_lock(&table->is_check);
	philo->meal_eat++;
	ph_print(philo, EAT);
	philo->last_eat = get_curr_time();
	pthread_mutex_unlock(&table->is_check);
	ph_usleep(table, table->time_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
}

void	is_die(t_table *table)
{
	int	i;

	while (!table->eat_all)
	{
		i = 0;
		while (!table->die && i++ < table->num_philo)
		{
			pthread_mutex_lock(&table->is_check);
			if (get_curr_time() - table->philo[i].last_eat > (size_t)table->die)
			{
				ph_print(&table->philo[i], DEAD);
				table->die = 1;
			}
			pthread_mutex_unlock(&table->is_check);
			usleep(100);
		}
		if (table->die)
			break ;
		i = 0;
		while (table->num_eat != 1 && i < table->num_philo && \
			table->philo[i].meal_eat >= table->num_eat)
			i++;
		if (i == table->num_philo)
			table->eat_all = 1;
	}
}
