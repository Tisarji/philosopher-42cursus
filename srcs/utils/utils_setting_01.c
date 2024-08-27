/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_setting_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 23:35:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/28 03:23:35 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ph_setting_time(pthread_mutex_t *mutex, time_t *time, time_t value)
{
	ptherad_mutex_lock(mutex);
	*time = value;
	pthread_mutex_unlock(mutex);
}

void	ph_setting_dead(pthread_mutex_t *mutex, bool *dead, bool value)
{
	pthread_mutex_lock(mutex);
	*dead = value;
	pthread_mutex_unlock(mutex);
}

bool	ph_getting(pthread_mutex_t *mutex, bool *dead)
{
	bool	tmp;

	pthread_mutex_lock(mutex);
	tmp = *dead;
	pthread_mutex_unlock(mutex);
	return (tmp);
}
