/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:15:14 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/10 01:44:55 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*hay_ptr;
	char	*need_ptr;

	if (!*needle)
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = len;
			hay_ptr = (char *)haystack + 1;
			need_ptr = (char *)needle + 1;
			while (i-- && *hay_ptr && *need_ptr && *hay_ptr == *need_ptr)
			{
				++hay_ptr;
				++need_ptr;
			}
			if (*need_ptr == '\0')
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
