/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:16:45 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/01 22:59:27 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static int	right_fork_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	if (!ph_action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->r_fork);
		return (0);
	}
	if (philo->table->num_philo == 1)
	{
		pthread_mutex_unlock(&philo->r_fork);
		return (0);
	}
	pthread_mutex_lock(philo->l_fork);
	if (!ph_action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (0);
	}
	return (1);
}

static int	left_fork_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (!ph_action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (0);
	}
	pthread_mutex_lock(&philo->r_fork);
	if (!ph_action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (0);
	}
	return (1);
}

static int	ph_finish_eat(t_philo *philo, int *eat_count)
{
	ph_setting(&philo->last_eat_mutex, &philo->last_eat, ph_get_timestamp(philo->table->start_milliseconds));
	*eat_count += 1;
	if (*eat_count == philo->table->must_time_eat)
	{
		pthread_mutex_lock(&philo->table->count_mutex);
		philo->table->count_remain += 1;
		pthread_mutex_unlock(&philo->table->count_mutex);
		return (0);
	}
	ph_msleep(philo->table->time_eat);
	return (1);
}

int	ph_eat(t_philo *philo, int *eat_count)
{
	int	tmp;

	if (philo->id % 2 && !right_fork_lock(philo))
		return (0);
	else if (philo->id % 2 == 0 && !left_fork_lock(philo))
		return (0);
	if (ph_action(philo, "is eating"))
		tmp = ph_finish_eat(philo, eat_count);
	else
		tmp = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	return (tmp);
}
