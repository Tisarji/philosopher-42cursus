/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 04:08:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/28 04:30:10 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	fork_routine(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->fork[philo->right_fork_id]);
	if (first_checker(philo, table))
		return (-1);
	ph_print_fork(philo);
	pthread_mutex_lock(&table->fork[philo->left_fork_id]);
	if (second_checker(philo, table))
		return (-1);
	ph_print_fork(philo);
	if (ph_getting(&philo->table->die_mutex, &philo->table->die))
		return (-1);
	return (0);
}

void	sub_routine(t_philo *philo, t_table *table)
{
	ph_print_eat(philo);
	eat
}

int	third_checker(t_philo *philo, t_table *table)
{
	if (ph_getting(&philo->table->die_mutex, &philo->table->die))
		return (-1);
	if (ph_getting_all_meal(&table->all_eat_mutex, &table->all_eat))
		return (-1);
	return (0);
}

int	second_checker(t_philo *philo, t_table *table)
{
	if (ph_getting(&philo->table->die_mutex, &philo->table->die))
	{
		pthread_mutex_unlock(&table->fork[philo->right_fork_id]);
		pthread_mutex_unlock(&table->fork[philo->left_fork_id]);
		return (1);
	}
	return (0);
}

int	first_checker(t_philo *philo, t_table *table)
{
	if (ph_getting(&philo->table->die_mutex, &philo->table->die))
	{
		pthread_mutex_unlock(&table->fork[philo->right_fork_id]);
		return (1);
	}
	return (0);
}
