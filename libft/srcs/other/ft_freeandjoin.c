/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeandjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:10:03 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/11 11:18:46 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_freeandjoin(char *buffer, char *aux)
{
	char	*strjoin;

	strjoin = ft_strjoin_for_other(buffer, aux);
	ft_multiple_free(2, buffer, aux);
	return (strjoin);
}
