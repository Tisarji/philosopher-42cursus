/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:30:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/07/18 18:59:05 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ph_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (i == 0)
		{
			pthread_mutex_destroy(&data->print);
			pthread_mutex_destroy(&data->monitor);
			pthread_mutex_destroy(&data->eat);
		}
		if (data->fork)
			pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	if (data->fork)
		free(data->fork);
	if (data->fork)
		free(data->philo);
}


void	ph_print(int id, t_data *data, int mode)
{
	if (mode == EAT)
	{
		pthread_mutex_lock(&data->eat);
		data->philo[id].last_spaghetti = get_curr_time(data);
		pthread_mutex_unlock(&data->eat);
	}
	pthread_mutex_lock(&data->print);
	if (mode == EAT && !data->dead)
	{
		if (data->philo[id].num_eat == data->time_must_eat)
			data->eat_verify++;
		printf("%s %lu %d is eating%s\n", GREEN, get_curr_time(data), id, RESET);
	}
	if (mode == FORK && !data->dead)
		printf("%s %lu %d has taken a fork%s\n", YELLOW, get_curr_time(data), id, RESET);
	if (mode == SLEEP && !data->dead)
		printf("%s %lu %d is sleeping%s\n", CYAN, get_curr_time(data), id, RESET);
	if (mode == THINK && !data->dead)
		printf("%s %lu %d is thinking%s\n", WHITE, get_curr_time(data), id, RESET);
	pthread_mutex_unlock(&data->print);
}

void	ph_sleep(t_data *data, time_t finish)
{
	time_t	start;

	start = get_curr_time(data) + finish;
	while (data->dead != 1)
	{
		if (get_curr_time(data) >= start)
			break ;
		usleep(200);
	}
}

time_t	get_curr_time(t_data *data)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 1)
		return (1);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - data->time_start);
}
