/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:52:32 by jikarunw          #+#    #+#             */
/*   Updated: 2023/08/30 12:35:19 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0 && s1[i] && s1[i] == s2[i])
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
