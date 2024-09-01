/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:27:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/29 04:31:44 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	ph_getting(pthread_mutex_t *mutex, int *value)
{
	int	return_data;

	pthread_mutex_lock(mutex);
	return_data = *value;
	pthread_mutex_unlock(mutex);
	return (return_data);
}

void	ph_setting(pthread_mutex_t *mutex, int *value, int next)
{
	pthread_mutex_lock(mutex);
	*value = next;
	pthread_mutex_unlock(mutex);
}
