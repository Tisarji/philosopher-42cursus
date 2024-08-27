/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:30:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/28 02:10:26 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ph_exit(t_table *table, pthread_t *thread)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
		pthread_join(thread[i], NULL);
	i = -1;
	while (++i < table->num_philo)
		pthread_mutex_destroy(&table->philo[i].fork);
	pthread_mutex_destroy(&table->is_print);
	pthread_mutex_destroy(&table->is_check);
	free(table->philo);
	free(thread);
}

size_t	get_curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	ph_usleep(t_table *table, size_t time_sleep)
{
	size_t	time;

	time = get_curr_time();
	while (1)
	{
		pthread_mutex_lock(&table->is_die_eat_all);
		if (table->die)
		{
			pthread_mutex_unlock(&table->is_die_eat_all);
			break ;
		}
		pthread_mutex_unlock(&table->is_die_eat_all);
		if (get_curr_time() - time >= time_sleep)
			break ;
		usleep(100);
	}
}
