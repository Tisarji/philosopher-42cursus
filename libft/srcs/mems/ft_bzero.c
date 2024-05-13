/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:37:52 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/08 20:41:24 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*super_c;
	unsigned int	i;

	super_c = (char *)s;
	i = 0;
	while (i < n)
	{
		*(super_c + i) = 0;
		i++;
	}
}
