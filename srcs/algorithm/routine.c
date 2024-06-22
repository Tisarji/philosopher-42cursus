/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:09:40 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/22 10:57:47 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	*routine(void *add)
{
	/** Consept:
	 *
	 * Made: function for each philosopher;
	 * 
	 * Take fork;
	 * Eat;
	 * Sleep;
	 * Think;
	 * Lock -> Fork -> Philo_id -> M_Dead;
	 * Repeat;
	 * Unlock -> Fork -> Philo_id -> M_Dead;
	 * 
	 */

	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)add;
	data = philo->data;
	if (philo->id % 2 == 0)
		ph_sleep(data, data->time_eat / 2);
	while (data->dead != 1 || data->eat_verify >= data->num_philo)
	{
		is_eat(philo, philo->id);
		if (philo->num_eat == data->time_must_eat)
			data->eat_verify++;
		ph_print(philo->id, data, SLEEP);
		ph_sleep(data, data->time_sleep);
		ph_print(philo->id, data, THINK);
		if (data->eat_verify >= data->num_philo)
			return (NULL);
	}
	return (NULL);
}
