/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:30:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/17 14:38:37 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 1)
		return (1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_error(char *str, int status)
{
	printf("%s%s%s\n", RED, str, RESET);
	exit(status);
}

void	print_msg(char *str, uint32_t color, int status)
{
	printf("%s%s%s", color, str, RESET);
	exit(status);
}
