/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_for_other.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:19:37 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/11 11:20:34 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin_for_other(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	j = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	strjoin = malloc ((j + 1) * sizeof(char));
	if (!strjoin)
		return (0);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = 0;
	return (strjoin);
}
