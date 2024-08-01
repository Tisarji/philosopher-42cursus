/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:11:30 by jikarunw          #+#    #+#             */
/*   Updated: 2024/07/28 13:40:18 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	is_eat(t_philo *philo, int id)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	ph_print(data->philo->id, data, FORK);
	if (data->num_philo == 1)
	{
		ph_sleep(data, data->time_die);
		printf("%s %lu %d died %s\n", RED, get_curr_time(data), id, RESET);
		data->dead = 1;
		pthread_mutex_unlock(&data->fork[philo->left_fork]);
		return ;
	}
	pthread_mutex_lock(&data->fork[philo->right_fork]);
	ph_print(philo->id, data, FORK);
	ph_print(philo->id, data, EAT);
	data->philo[id - 1].num_eat++;
	ph_sleep(data, data->time_eat);
	pthread_mutex_unlock(&(data->fork[philo->left_fork]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork]));
}

void	init_fork(t_data *data)
{
	int	i;

	i = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	while (++i < data->num_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	if (pthread_mutex_init(&(data->print), NULL) != 0)
		return (ph_exit(data));
	if (pthread_mutex_init(&(data->monitor), NULL) != 0)
		return (ph_exit(data));
	if (pthread_mutex_init(&(data->eat), NULL) != 0)
		return (ph_exit(data));
	data->dead = 0;
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	while (++i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_spaghetti = 0;
		data->philo[i].num_eat = 0;
		data->philo[i].left_fork = i;
		if (data->num_philo > 1)
			data->philo[i].right_fork = ((i + 1) % data->num_philo);
		data->philo[i].data = data;
	}
	data->time_start = get_curr_time(data);
	return (0);
}
