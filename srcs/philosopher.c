/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:03:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/01 23:01:08 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*philo;

	if (handle_arg(&table, ac, av))
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	philo = init_philos(&table);
	if (!philo || start_simulation(philo))
		return (write(2, "Memory error\n", 14), 1);
	ph_cleanup(philo);
}
