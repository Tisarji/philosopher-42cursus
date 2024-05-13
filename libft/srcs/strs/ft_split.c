/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 01:24:08 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/26 18:21:07 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_count_substrings(char const *s, char c)
{
	size_t	arrays_counter;
	size_t	s_index;

	s_index = 0;
	arrays_counter = 1;
	while (s[s_index])
	{
		if (s[s_index] == c)
			s_index++;
		else if (s[s_index] != c)
		{
			if (s[s_index + 1] == c || s[s_index + 1] == '\0')
				arrays_counter++;
			s_index++;
		}
	}
	return (arrays_counter);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_array;
	char	*start;
	size_t	index;

	index = 0;
	start = (char *)s;
	splited_array = (char **)malloc(sizeof(char *) * (ft_count_substrings(s,
					c)));
	if (s == NULL || splited_array == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			if (s > start)
				splited_array[index++] = ft_substr(start, 0, (s - start));
			start = (char *)(s + 1);
		}
		s++;
	}
	if (s > start)
		splited_array[index++] = ft_substr(start, 0, (s - start));
	splited_array[index] = NULL;
	return (splited_array);
}
