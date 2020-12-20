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
	int				len;
	long int		nbr;
	int				negative;

	nbr = va_arg(argptr, int);
	negative = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		negative = 1;
	}
	len = ft_digit_len(nbr, 10);
	ft_digits_processor(data, nbr, len, negative);
}

void	ft_print_unsigned(t_ft_printf *data, va_list argptr)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(argptr, unsigned int);
	len = ft_digit_len(nbr, 10);
	ft_digits_processor(data, nbr, len, 0);
}

void	ft_minus_digit(t_ft_printf *data, unsigned int long nbr, int len,
															int negative)
{
	if (negative)
	{
		ft_putchar('-');
		data->count++;
	}
	data->count += print_width_and_precision(data->precision - len,
							0, '0');
	if (data->type == 'd' || data->type == 'u')
		data->count += ft_putnbr(nbr);
	else
	{
		if (data->type == 'p')
		{
			data->width -= 2;
			data->count += ft_putstr("0x", 2);
		}
		ft_puthex(data, nbr, nbr);
	}
	if (data->width > data->precision && data->precision < len)
		data->width = data->width - len;
	else
		data->width = data->width - data->precision;
	data->count += print_width_and_precision(data->width, 0, ' ');
}

void	ft_zero_digit(t_ft_printf *data, unsigned int long nbr, int len,
															int negative)
{
	char s;

	if (data->width > data->precision && data->precision < len)
		data->width = data->width - len;
	else
		data->width = data->width - data->precision;
	if (!data->precision && !data->point)
		s = '0';
	else
		s = ' ';
	data->count += print_width_and_precision(data->width, 0, s);
	if (negative)
	{
		ft_putchar('-');
		data->count++;
	}
	data->count += print_width_and_precision(data->precision - len, 0, '0');
	if (data->type == 'd' || data->type == 'u')
		data->count += ft_putnbr(nbr);
	else
	{
		if (data->type == 'p')
			data->count += ft_putstr("0x", 2);
		ft_puthex(data, nbr, nbr);
	}
}
