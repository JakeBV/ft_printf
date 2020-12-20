/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:44:54 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:44:55 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_ft_printf *data, va_list argptr)
{
	char	s;
	char	c;

	c = '%';
	if (data->type != '%')
		c = va_arg(argptr, int);
	if (data->flag == '-')
	{
		ft_putchar(c);
		data->count += print_width_and_precision(data->width - 1, 1, ' ');
	}
	else
	{
		s = ' ';
		if (data->type == '%')
			s = '0';
		data->count += print_width_and_precision(data->width - 1, 1, s);
		ft_putchar(c);
	}
}
