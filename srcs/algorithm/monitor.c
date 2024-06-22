/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:22:07 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/18 22:23:40 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	monitor(t_data *data)
{
	int	i;

	while (data->dead != 1 && data->eat_verify <= data->num_philo)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			pthread_mutex_lock(&data->eat);
			if (data->eat_verify == data->num_philo)
			{
				pthread_mutex_unlock(&data->eat);
				return ;
			}
			pthread_mutex_unlock(&data->eat);
		}
	}
	return ;
}
