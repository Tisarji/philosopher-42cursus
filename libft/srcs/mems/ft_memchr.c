/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:54:01 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/08 20:42:18 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sourc_char;
	unsigned int	i;

	sourc_char = (unsigned char *)s;
	i = 0;
	while (i < n && sourc_char[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)&sourc_char[i]);
}
