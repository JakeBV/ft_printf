/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_processors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:27:37 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/21 01:27:38 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_processor(char *str_after_precision, t_ft_printf *data,
						va_list argptr)
{
	data->type = *str_after_precision;
	if (*str_after_precision == 'c' || *str_after_precision == '%')
		ft_print_char(data, argptr);
	else if (*str_after_precision == 's')
		ft_print_string(data, argptr);
	else if (*str_after_precision == 'd' || *str_after_precision == 'i')
	{
		data->type = 'd';
		ft_print_digit(data, argptr);
	}
	else if (*str_after_precision == 'u')
		ft_print_unsigned(data, argptr);
	else if (*str_after_precision == 'x' || *str_after_precision == 'X' ||
			*str_after_precision == 'p')
		ft_print_hex(data, argptr);
	return (str_after_precision);
}

void	ft_digits_processor(t_ft_printf *data)
{
	if (data->is_negative)
		data->width--;
	if (!data->digit && !data->precision && data->dot)
		data->count += ft_print_width(data->width, 0, ' ');
	else if (data->flag == '-')
		ft_minus_digit(data);
	else
		ft_zero_digit(data);
}

void	ft_negative_processor(t_ft_printf *data)
{
	if (data->is_negative)
	{
		ft_putchar('-');
		data->count++;
	}
}

void	ft_print_processor(t_ft_printf *data)
{
	if (data->type == 'd' || data->type == 'u')
		data->count += ft_putnbr(data->digit);
	else
	{
		if (data->type == 'p')
		{
			data->count += ft_putstr("0x", 2);
			ft_puthex(data, data->pointer, data->pointer);
		}
		else
			ft_puthex(data, data->digit, data->digit);
	}
}

void	ft_width_processor(t_ft_printf *data)
{
	if (data->width > data->precision && data->precision < data->len)
		data->width = data->width - data->len;
	else
		data->width = data->width - data->precision;
}
