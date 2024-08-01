/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:03:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/07/07 15:27:57 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	join_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_join(data->philo[i].thread, NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	if (handle_arg(argc, argv, &data))
		return (1);
	init_philo(&data);
	init_fork(&data);
	i = -1;
	while (++i < data.num_philo)
	{
		if (pthread_create(&data.philo[i].thread, NULL, &routine, &data.philo[i]))
			return (ph_exit(&data), 1);
	}
	ph_sleep(&data, 10);
	monitor(&data);
	join_thread(&data);
}
