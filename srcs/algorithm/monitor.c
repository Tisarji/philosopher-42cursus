/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:11:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/04 12:49:33 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static void	report_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->start_mutex);
	pthread_mutex_lock(&philo->table->print_mutex);
	philo->table->start = 0;
	printf("%ld %d died\n", ph_get_timestamp(philo->table->start_milliseconds), \
		philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);
	pthread_mutex_unlock(&philo->table->start_mutex);
}

static int	detect_death(t_philo *philo)
{
	suseconds_t	ts;
	int			return_code;

	pthread_mutex_lock(&philo->last_eat_mutex);
	ts = ph_get_timestamp(philo->table->start_milliseconds);
	if (ts - philo->table->time_die >= philo->last_eat)
		return_code = 1;
	else
		return_code = 0;
	pthread_mutex_unlock(&philo->last_eat_mutex);
	return (return_code);
}

void	monitor_philosophers(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->table->num_philo)
		{
			if (detect_death(philo + i))
			{
				report_death(philo + i);
				return ;
			}
			if (ph_getting(&philo->table->count_mutex, \
				&philo->table->count_remain) == philo->table->num_philo)
			{
				ph_setting(&philo->table->start_mutex, &philo->table->start, 0);
				return ;
			}
			i += 1;
		}
		ph_msleep(1);
	}
}

int	start_simulation(t_philo *philo)
{
	int				i;
	t_table			*table;
	struct timeval	tv;

	i = 0;
	table = philo->table;
	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error gettingtimeofday\n");
		return (1);
	}
	philo->table->start_milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	while (i < table->num_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, \
			(void *(*)(void *))routine, &philo[i]))
		{
			ph_resources_destroy(philo, i - 1, true);
			ph_setting(&table->start_mutex, &table->start, -1);
			return (1);
		}
		i += 1;
	}
	monitor_philosophers(philo);
	return (0);
}
