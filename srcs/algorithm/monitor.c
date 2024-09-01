/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:11:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/08/29 05:11:06 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static void	report_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->opt->run_m);
	pthread_mutex_lock(&philo->opt->print_m);
	philo->opt->run = 0;
	printf("%ld %d died\n", get_timestamp(philo->opt->start), philo->num);
	pthread_mutex_unlock(&philo->opt->print_m);
	pthread_mutex_unlock(&philo->opt->run_m);
}

static int	detect_death(t_philo *philo)
{
	suseconds_t	ts;
	int			ret;

	pthread_mutex_lock(&philo->m_last_ate);
	ts = get_timestamp(philo->opt->start);
	if (ts - philo->opt->t_die >= philo->last_ate)
		ret = 1;
	else
		ret = 0;
	pthread_mutex_unlock(&philo->m_last_ate);
	return (ret);
}

void	monitor_philosophers(t_philo *philo)
{
	int			i;

	while (1)
	{
		i = 0;
		while (i < philo->opt->p_count)
		{
			if (detect_death(philo + i))
			{
				report_death(philo + i);
				return ;
			}
			if (qmutex_get(&philo->opt->count_m, &philo->opt->rem_count)
				== philo->opt->p_count)
			{
				qmutex_set(&philo->opt->run_m, &philo->opt->run, 0);
				return ;
			}
			i += 1;
		}
		msleep(1);
	}
}

int	start_simulation(t_philo *philo)
{
	int				i;
	t_table			*table;
	struct timeval	tv;

	i = 0;
	table = philo->table;
	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error gettingtimeofday\n");
		return (1);
	}
	philo->table->start_millisecond = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (i < table->num_philo)
	{
		if (pthread_create(&philo[i].thread, NULL,(void *(*)(void *))routine, &philo[i]))
		{
			destruct_partial(philo, i - 1, true);
			qmutex_set(&opt->run_m, &opt->run, -1);
			return (1);
		}
		i += 1;
	}
	monitor_philosophers(philo);
	return (0);
}
