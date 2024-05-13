/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:19:59 by jikarunw          #+#    #+#             */
/*   Updated: 2024/05/13 17:06:57 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	handle_data(t_philo *data)
{
	if (data->action.time_eat == 0 || data->action.time_die == 0 \
		|| data->action.time_sleep == 0 || data->action.fork == 0 \
		|| data->action.num_philo == 0)
		return (1);
	return (0);
}

void	read_data(int argc, char *argv[], t_philo *philo)
{
	philo->action.num_philo = ft_atoi(argv[1]);
	philo->action.fork = ft_atoi(argv[1]);
	philo->action.time_eat = ft_atoi(argv[2]);
	philo->action.time_die = ft_atoi(argv[3]);
	philo->action.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->action.time_eat = ft_atoi(argv[5]);
	else
		philo->action.time_eat = -1;
}

int	handle_arg(int argc, char *argv[], t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	read_data(argc, argv, philo);
	if (handle_data(philo))
	{
		ft_error("Error: Data", 0);
		return (1);
	}
	return (0);
}
