/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:17:38 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/04 01:17:58 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_hex_to_dec(const char *hex)
{
	int		len;
	int		dec;
	int		base;
	char	c;

	len = ft_strlen(hex);
	dec = 0;
	base = 1;
	while (len-- > 0)
	{
		c = hex[len];
		if (c >= '0' && c <= '9')
			dec += (c - '0') * base;
		else if (c >= 'a' && c <= 'f')
			dec += (c - 'a' + 10) * base;
		else if (c >= 'A' && c <= 'F')
			dec += (c - 'A' + 10) * base;
		base *= 16;
	}
	return (dec);
}
