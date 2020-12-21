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

void	ft_minus_digit(t_ft_printf *data, unsigned long int nbr, int len,
															int negative)
{
	ft_negative_processor(data, negative);
	data->count += print_width_and_precision(data->precision - len,
							0, '0');
	ft_print_processor(data, nbr);
	ft_width_processor(data, len);
	data->count += print_width_and_precision(data->width, 0, ' ');
}

void	ft_zero_digit(t_ft_printf *data, unsigned int nbr, int len,
															int negative)
{
	char s;

	ft_width_processor(data, len);
	if (!data->precision && !data->point && data->flag != 0)
		s = '0';
	else
		s = ' ';
	if (data->flag == '0' && !data->point)
	{
		ft_negative_processor(data, negative);
		data->count += print_width_and_precision(data->width, 0, s);
	}
	else
	{
		data->count += print_width_and_precision(data->width, 0, s);
		ft_negative_processor(data, negative);
	}
	data->count += print_width_and_precision(data->precision - len, 0, '0');
	ft_print_processor(data, nbr);
}
