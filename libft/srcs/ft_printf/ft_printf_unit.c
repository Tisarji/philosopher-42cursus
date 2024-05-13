/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:22:26 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/18 15:15:01 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unit(unsigned int n)
{
	int	digit;

	digit = 0;
	if (n > 9)
		digit += ft_printf_unit((n / 10));
	digit += ft_printf_char((n % 10) + 48);
	return (digit);
}
