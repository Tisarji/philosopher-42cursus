/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:35:42 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/18 16:45:54 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_hex_adr(unsigned long long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static int	ft_hex_adr(unsigned long long n)
{
	char	*base_16;
	int		size;

	size = ft_size_hex_adr(n);
	base_16 = "0123456789abcdef";
	while (size > 0)
	{
		size--;
		ft_printf_char(base_16[(n >> (size * 4)) & 0xf]);
	}
	return (ft_size_hex_adr(n));
}

int	ft_printf_ptr(void *ptr)
{
	int	n;

	if (ft_printf_string("0x") == -1)
		return (-1);
	n = ft_hex_adr((unsigned long long) ptr);
	if (n != 0)
		return (n + 2);
	else
		return (3);
}
