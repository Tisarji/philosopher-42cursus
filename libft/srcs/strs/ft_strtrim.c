/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 23:06:55 by jikarunw          #+#    #+#             */
/*   Updated: 2023/08/31 23:27:32 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	outstr_strat;
	size_t	outstr_end;

	if (!s1 || !set)
		return (NULL);
	outstr_strat = 0;
	while (s1[outstr_strat] && is_in_set(s1[outstr_strat], set))
		outstr_strat++;
	outstr_end = ft_strlen(s1);
	while (outstr_end > outstr_strat && is_in_set(s1[outstr_end - 1], set))
		outstr_end--;
	str = (char *)malloc(sizeof(*s1) * (outstr_end - outstr_strat + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (outstr_strat < outstr_end)
		str[i++] = s1[outstr_strat++];
	str[i] = 0;
	return (str);
}
