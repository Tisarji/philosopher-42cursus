/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:30:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/20 09:32:07 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ft_exit(t_data *data)
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
		if (&data->fork[i])
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
		printf("%lu %d is eating\n", get_curr_time(data), id);
	}
	if (mode == FORK && !data->dead)
		printf("%lu %d has taken a fork\n", get_curr_time(data), id);
	if (mode == SLEEP && !data->dead)
		printf("%lu %d is sleeping\n", get_curr_time(data), id);
	if (mode == THINK && !data->dead)
		printf("%lu %d is thinking\n", get_curr_time(data), id);
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
