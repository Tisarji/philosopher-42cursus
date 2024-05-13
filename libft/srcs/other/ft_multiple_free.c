/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:02:18 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/04 01:02:41 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_multiple_free(int num_args, ...)
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
}
