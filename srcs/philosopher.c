/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:03:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/04 12:46:15 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*philo;

	if (handle_arg(&table, ac, av))
	{
		printf("\tUsage: ./philo num_philo | time die | ");
		printf ("time eat | time sleep | Much time to eat\n");
		return (1);
	}
	philo = init_philos(&table);
	if (!philo || start_simulation(philo))
		return (write(2, "Memory error\n", 14), 1);
	ph_cleanup(philo);
}
