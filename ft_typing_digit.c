/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:45:02 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:45:03 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_digit(t_ft_printf *data, va_list argptr)
{
	long int		nbr;

	nbr = va_arg(argptr, int);
	if (nbr < 0)
	{
		nbr = -nbr;
		data->is_negative = 1;
	}
	data->digit = nbr;
	data->len = ft_digit_len(nbr, 10);
	ft_digits_processor(data);
}

void	ft_print_unsigned(t_ft_printf *data, va_list argptr)
{
	data->digit = va_arg(argptr, unsigned int);
	data->len = ft_digit_len(data->digit, 10);
	ft_digits_processor(data);
}

int		ft_digit_len(unsigned int n, unsigned int numsys)
{
	if (n < numsys)
		return (1);
	return (1 + ft_digit_len(n / numsys, numsys));
}

void	ft_minus_digit(t_ft_printf *data)
{
	ft_negative_processor(data);
	data->count += ft_print_width(data->precision - data->len,
							0, '0');
	ft_print_processor(data);
	ft_width_processor(data);
	data->count += ft_print_width(data->width, 0, ' ');
}

void	ft_zero_digit(t_ft_printf *data)
{
	char s;

	ft_width_processor(data);
	if (!data->precision && !data->dot && data->flag != 0)
		s = '0';
	else
		s = ' ';
	if (data->flag == '0' && !data->dot)
	{
		ft_negative_processor(data);
		data->count += ft_print_width(data->width, 0, s);
	}
	else
	{
		data->count += ft_print_width(data->width, 0, s);
		ft_negative_processor(data);
	}
	data->count += ft_print_width(data->precision - data->len, 0, '0');
	ft_print_processor(data);
}
