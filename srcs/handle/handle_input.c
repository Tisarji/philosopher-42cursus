/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:19:59 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/27 20:47:37 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static void	init_table(t_table *table)
{
	int	i;

	table->die = 0;
	table->eat_all = 0;
	table->philo = (t_philo *)malloc(table->num_philo * sizeof(t_philo));
	i = -1;
	while (++i < table->num_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].table = table;
		table->philo[i].meal_eat = 0;
		if (i + 1 == table->num_philo)
			table->philo[i].r_fork = &table->philo[0];
		else
			table->philo[i].r_fork = &table->philo[i + 1];
		if (i == 0)
			table->philo[i].l_fork = &table->philo[table->num_philo - 1];
		else
			table->philo[i].l_fork = &table->philo[i - 1];
		pthread_mutex_init(&table->philo[i].fork, NULL);
	}
	pthread_mutex_init(&table->is_print, NULL);
	pthread_mutex_init(&table->is_check, NULL);
	pthread_mutex_init(&table->is_die_eat_all, NULL);
}

static int	check_valid(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '-')
			return (1);
		else if (argv[i][0] == '+')
			j++;
		if (!ft_isdigit(argv[i][j + 1]))
			return (1);
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

static int	is_int(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (*s == '+' && s++)
		len--;
	while (*s == '0' && *s && len--)
		s++;
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	if (ft_strncmp(s, "2147483648", 10) >= 0)
		return (1);
	return (0);
}

static int	check_arg(int argc, char *argv[])
{
	int	i;

	if (check_valid(argc, argv))
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (is_int(argv[i]))
			return (1);
	}
	return (0);
}

int	handle_arg(int argc, char *argv[], t_table *table)
{
	if (check_arg(argc, argv))
		return (1);
	table->num_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	table->num_eat = -1;
	if (argc == 6)
		table->num_eat = ft_atoi(argv[5]);
	init_table(table);
	return (0);
}
