/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:03:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/05 16:48:08 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int argc, char *argv[])
{
	int			i;
	t_table		table;
	pthread_t	*thread;

	if ((argc < 5 || argc > 6) || handle_arg(argc, argv, &table))
	{
		printf("Usage: ./philo [Num Philo <= 5] [Die Time] \
			[Eat Time] [Sleep Time] [Time Much Eat]");
		return (EXIT_FAILURE);
	}
	thread = (pthread_t *)malloc(table.num_philo * sizeof(pthread_t));
	table.table_init = get_curr_time();
	i = 0;
	while (i++ < table.num_philo)
	{
		if (pthread_create(&thread[i], NULL, &routine, &thread))
		{
			printf("Error: Cannot Create");
			free(table.philo);
			free(thread);
			return (EXIT_FAILURE);
		}
		pthread_mutex_lock(&table.is_check);
		table.philo[i].last_eat = table.table_init;
		pthread_mutex_unlock(&table.is_check);
	}
	return (EXIT_SUCCESS);
}
