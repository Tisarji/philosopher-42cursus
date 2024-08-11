/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:30:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/08 16:15:33 by jikarunw         ###   ########.fr       */
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
	while (!(table->die))
	{
		if (get_curr_time() - time >= time_sleep)
			break ;
		usleep(100);
	}
}

static char *ph_color_massage(int msg)
{
	if (msg == FORK)
		return (YELLOW);
	if (msg == EAT)
		return (GREEN);
	if (msg == SLEEP)
		return (CYAN);
	if (msg == THINK)
		return (PURPLE);
	if (msg == DEAD)
		return (RED);
	return ("Error: Valid");
}

static char *ph_massage(int msg)
{
	if (msg == FORK)
		return ("has taken a fork");
	if (msg == EAT)
		return ("is eating");
	if (msg == SLEEP)
		return ("is sleeping");
	if (msg == THINK)
		return ("is thinking");
	if (msg == DEAD)
		return ("died");
	return ("Error: Valid");
}

void	ph_print(t_philo *philo, int msg)
{
	size_t	time;
	time = get_curr_time() - philo->table->table_init;
	pthread_mutex_lock(&philo->table->is_print);
	if (!philo->table->die && !philo->table->eat_all)
	{
		printf(BLACK"%6ld ms", time);
		printf(CYAN" %3d ", philo->id);
		printf("%s%s%s", ph_color_massage(msg), ph_massage(msg), RESET);
		if (msg == EAT)
			printf("%s - %d%s", GREEN, philo->meal_eat, RESET);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->table->is_print);
}
