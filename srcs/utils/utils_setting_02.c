/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_setting_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:45:28 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/28 01:30:22 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ph_setting_meal(pthread_mutex_t *mutex, int *nb_meal, int value)
{
	pthread_mutex_lock(mutex);
	*nb_meal = *nb_meal + value;
	pthread_mutex_unlock(mutex);
}

int	ph_getting_meal(pthread_mutex_t *mutex, int *nb_meal)
{
	int	tmp;

	pthread_mutex_lock(mutex);
	tmp = *nb_meal;
	pthread_mutex_unlock(mutex);
	return (tmp);
}

void	ph_setting_all_meal(pthread_mutex_t *mutex, int *all_eat, int value)
{
	pthread_mutex_lock(mutex)
	*all_eat = value;
	pthread_mutex_unlock(mutex);
}

int	ph_getting_all_meal(pthread_mutex_t *mutex, int *all_eat)
{
	int	tmp;

	pthread_mutex_lock(mutex);
	tmp = *all_eat;
	pthread_mutex_unlock(mutex);
	return (tmp);
}

time_t	ph_getting_time(pthread_mutex_t *mutex, time_t *time)
{
	time_t	tmp;

	pthread_mutex_lock(mutex);
	tmp = *time;
	pthread_mutex_unlock(mutex);
	return (tmp);
}
