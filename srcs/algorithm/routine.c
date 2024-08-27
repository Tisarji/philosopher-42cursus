/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:09:40 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/28 04:31:46 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	*routine(void *add)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)add;
	table = philo->table;
	if (philo->id % 2 == 0)
		usleep(15000); // usleep(1000);
	while (!ph_getting(&table->die_mutex, &table->die))
	{
		if (fork_routine(table, philo)) /** Create function for routine only fork! */
			return (NULL);
		sub_routine(table, philo); /** Support Routine For check */
		if (third_checker(philo, table)) /**Create function for check routine it */
			return (NULL);
		ph_print_sleep(philo);
		check_sleep(table); /** Check for sure this got sleep */
		if (ph_getting(&philo->table->die_mutex, &philo->table->die))
			return (NULL);
		ph_print_think(philo);
	}
	return (NULL);
}
