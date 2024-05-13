/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:31:15 by jikarunw          #+#    #+#             */
/*   Updated: 2024/05/11 17:32:21 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_printf(const char *input, unsigned int i, va_list *args)
{
	unsigned int	count;

	count = 0;
	if (input[i] == 'd')
		count += ft_printf_nbr(va_arg(*args, int));
	else if (input[i] == 'c')
		count += ft_printf_char(va_arg(*args, int));
	else if (input[i] == 's')
		count += ft_printf_string(va_arg(*args, char *));
	else if (input[i] == 'p')
		count += ft_printf_ptr(va_arg(*args, void *));
	else if (input[i] == 'x')
		count += ft_printf_hex(va_arg(*args, int), 1);
	else if (input[i] == 'X')
		count += ft_printf_hex(va_arg(*args, int), 0);
	else if (input[i] == 'u')
		count += ft_printf_unit(va_arg(*args, unsigned int));
	else if (input[i] == 'i')
		count += ft_printf_nbr(va_arg(*args, int));
	else if (input[i] == '%')
	{
		ft_printf_char('%');
		return (1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_handle_printf(str, i, &args);
		}
		else
			len += ft_printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
