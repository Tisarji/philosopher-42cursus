/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:11:50 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/04 01:12:16 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_count_words(const char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (ft_isspace(*line) == 0 && (ft_isspace(*(line + 1)) || !line[1]))
			i++;
		line++;
	}
	return (i);
}
