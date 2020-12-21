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

void	ft_negative_processor(t_ft_printf *data, int negative)
{
	if (negative)
	{
		ft_putchar('-');
		data->count++;
	}
}

void 	ft_print_processor(t_ft_printf *data, unsigned long int nbr)
{
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
}

void 	ft_width_processor(t_ft_printf *data, int len)
{
	if (data->width > data->precision && data->precision < len)
		data->width = data->width - len;
	else
		data->width = data->width - data->precision;
}
