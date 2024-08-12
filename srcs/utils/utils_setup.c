/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:45:28 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/11 20:16:41 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ph_setlock_eat(t_table *table, int *eat, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	if (table)
		*eat = table->eat_all;
}

void	ph_setlock_die(t_table *table ,int *die, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	if (table)
		*die = table->die;
}

void	ph_setunlock(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
}
