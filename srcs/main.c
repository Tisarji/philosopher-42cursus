/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:03:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/14 19:55:40 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo = NULL;

	if (argc == 5 || argc == 6)
	{
		if (handle_arg(argc, argv, philo))
			return (1);
		read_data(argc, argv, philo);
		return (0);
	}
	else
	{
		if (argc < 5)
			ft_error("Error: Nedd More Argument", 0);
		else if (argc > 6)
			ft_error("Error: Too Much Argument", 0);
	}
	return (0);
}
