/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:19:59 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/15 11:22:06 by jikarunw         ###   ########.fr       */
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
	long start_time, end_time;

	start_time = get_time();
	philo->action.num_philo = ft_atoi(argv[1]);
	philo->action.fork = ft_atoi(argv[1]);
	end_time = get_time();
	printf("Time taken for action [num_philo] and [fork]: %ld\n", end_time - start_time);

	start_time = get_time();
	philo->action.time_eat = ft_atoi(argv[2]);
	end_time = get_time();
	printf("Time taken for action [time_eat]: %ld\n", end_time - start_time);

	start_time = get_time();
	philo->action.time_die = ft_atoi(argv[3]);
	end_time = get_time();
	printf("Time taken for action [time_die]: %ld\n", end_time - start_time);
	
	start_time = get_time();
	philo->action.time_sleep = ft_atoi(argv[4]);
	end_time = get_time();
	printf("Time taken for action [time_sleep]: %ld\n", end_time - start_time);
	
	if (argc == 6)
	{
		start_time = get_time();
		philo->action.time_eat = atoi(argv[5]);
		end_time = get_time();
		printf("Time taken for action (MUST) - [time_eat]: %ld\n", end_time - start_time);
	}
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
