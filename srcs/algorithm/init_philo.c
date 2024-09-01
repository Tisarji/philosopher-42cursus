/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:11:30 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/01 21:56:37 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static int	init_table(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&table->start_mutex, NULL))
		return (pthread_mutex_destroy(&table->print_mutex), 1);
	if (pthread_mutex_init(&table->count_mutex, NULL))
	{
		pthread_mutex_destroy(&table->print_mutex);
		pthread_mutex_destroy(&table->start_mutex);
		return (1);
	}
	table->start = 1;
	table->count_remain = 0;
	return (0);
}

static int	ph_setup_philo(t_philo *philo, t_table *table)
{
	int				i;
	pthread_mutex_t	*prev;

	i = 0;
	prev = NULL;
	while (i < table->num_philo)
	{
		philo[i].table = table;
		philo[i].l_fork = prev;
		philo[i].id = i + 1;
		philo[i].last_eat = 0;
		if (pthread_mutex_init(&philo[i].r_fork, NULL))
			return (ph_resources_destroy(philo, i - 1, false), free(philo), 1);
		if (pthread_mutex_init(&philo[i].last_eat_mutex, NULL))
		{
			pthread_mutex_destroy(&philo[i].last_eat_mutex);
			return (ph_resources_destroy(philo, i - 1, false), free(philo), 1);
		}
		prev = &philo[i].r_fork;
		i += 1;
	}
	philo[0].l_fork = prev;
	return (0);
}

t_philo	*init_philos(t_table *table)
{
	t_philo	*philo;

	if (init_table(table))
		return (NULL);
	philo = malloc(sizeof(t_philo) * table->num_philo);
	if (!philo)
		return (NULL);
	if (ph_setup_philo(philo, table))
		return (NULL);
	return (philo);
}
