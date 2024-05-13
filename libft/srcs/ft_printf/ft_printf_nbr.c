/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:49 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/18 17:56:38 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_digits(int num)
{
	int	digit;
	int	div;
	int	temp;

	digit = 0;
	div = 1;
	temp = num;
	while (temp >= 10)
	{
		temp /= 10;
		div *= 10;
	}
	while (div > 0)
	{
		digit += ft_printf_char('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (digit);
}

int	ft_printf_nbr(int num)
{
	int	digit;

	digit = 0;
	if (num == INT_MIN)
		return (ft_printf_string("-2147483648"));
	else if (num < 0)
	{
		digit += ft_printf_char('-');
		num *= -1;
	}
	digit += ft_print_digits(num);
	return (digit);
}
