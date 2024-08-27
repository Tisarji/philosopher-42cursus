/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:47:07 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/28 02:09:55 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ph_print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->is_print);
	printf("%ld %d died\n", get_curr_time() - philo->table->table_init, philo->id);
	pthread_mutex_unlock(&philo->table->is_print);
}

void	ph_print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->is_print);
	printf("%ld %d is thinking\n", get_curr_time() - philo->table->table_init, philo->id);
	pthread_mutex_unlock(&philo->table->is_print);
	if (philo->table->num_philo % 2 != 0)
		usleep(100);
}

void	ph_print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->is_print);
	printf("%ld %d is eatting\n", get_curr_time() - philo->table->table_init, philo->id);
	ph_setting_time(&philo->table->is_check, &philo->last_eat, get_curr_time());
	pthread_mutex_unlock(&philo->table->is_print);
}

void	ph_print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->is_print);
	printf("%ld %d is sleeping\n", get_curr_time() - philo->table->table_init, philo->id);
	pthread_mutex_unlock(&philo->table->is_print);
}

void	ph_print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->is_print);
	printf("%ld %d has taken a fork\n", get_curr_time() - philo->table->table_init, philo->id);
	pthread_mutex_unlock(&philo->table->is_print);
}
