/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:09:40 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/29 04:15:30 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	*routine(t_philo *philo)
{
	int	eat_count;

	eat_count = 0;
	if (!ph_action(philo, "is thinking"))
		return (NULL);
	while (1)
	{
		if (self->num % 2)
			ph_msleep(6);
		if (!eat(philo, &eat_count))
			break ;
		if (!ph_action(philo, "is sleeping"))
			break ;
		ph_msleep(philo->table->time_sleep);
		if (!ph_action(philo, "is thinking"))
			break ;
		ph_msleep(philo->table->time_eat - philo->table->time_sleep);
	}
	return (NULL);
}
