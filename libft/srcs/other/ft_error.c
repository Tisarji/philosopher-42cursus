/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:40:46 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/12 15:15:23 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_error(char *prompt, int num_args, ...)
{
	va_list	args;
	void	*ptr;
	int		i;

	i = -1;
	va_start(args, num_args);
	while (++i < num_args)
	{
		ptr = va_arg(args, void *);
		ft_free_and_null((void **)&ptr);
	}
	va_end(args);
	ft_putstr_fd("\033[31;1m", 2);
	ft_putstr_fd(prompt, 2);
	ft_putstr_fd("\n\033[0m", 2);
	exit(EXIT_FAILURE);
}
