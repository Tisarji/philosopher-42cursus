/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:22:07 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/11 16:10:05 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*l_o;

	l_o = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			l_o = (char *)&s[i];
		i++;
	}
	if ((char) c == s[i])
		return ((char *)&s[i]);
	return (l_o);
}
