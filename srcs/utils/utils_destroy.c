/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:36:57 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/01 21:53:50 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ph_destroy(t_table *table)
{
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->start_mutex);
	pthread_mutex_destroy(&table->count_mutex);
}

void	ph_resources_destroy(t_philo *philo, int num, bool thread)
{
	int		i;
	void	*ptr;

	i = 0;
	while (i < num)
	{
		if (thread)
			pthread_join(philo[i].thread, &ptr);
		pthread_mutex_destroy(&philo[i].r_fork);
		i++;
	}
	if (thread)
	{
		while (i < philo->table->num_philo)
		{
			pthread_mutex_destroy(&philo[i].r_fork);
			i++;
		}
	}
	ph_destroy(philo->table);
}

void	ph_cleanup(t_philo *philo)
{
	int			i;
	t_table		*table;
	void		*ptr;

	i = 0;
	table = philo->table;
	while (i < table->num_philo)
	{
		pthread_join(philo[i].thread, &ptr);
		i++;
	}
	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_destroy(&philo[i].r_fork);
		i++;
	}
	ph_destroy(table);
	free(philo);
}
