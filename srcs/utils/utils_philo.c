/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:30:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/09/01 21:53:22 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

static long	ph_mstime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ph_action(t_philo *philo, const char *action)
{
	suseconds_t	millisecond;
	int			return_code;

	return_code = 0;
	pthread_mutex_lock(&philo->table->start_mutex);
	if (philo->table->start)
	{
		millisecond = ph_get_timestamp(philo->table->start_milliseconds);
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", millisecond, philo->id, action);
		pthread_mutex_unlock(&philo->table->print_mutex);
		return_code = 1;
	}
	pthread_mutex_unlock(&philo->table->start_mutex);
	return (return_code);
}

/** Note: About Time!
 * suseconds_t	Milliseconds
 * time_t		Seconds
**/

suseconds_t	ph_get_timestamp(suseconds_t milliseconds)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_usec / 1000 + tv.tv_sec * 1000 - milliseconds);
}

void	ph_msleep(int msec)
{
	long	limits;

	limits = ph_mstime() + msec;
	while (limits > ph_mstime())
		usleep(500);
}
