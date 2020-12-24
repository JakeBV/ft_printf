/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:45:18 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:45:20 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_ft_printf *data, va_list argptr)
{
	char	*str;

	str = va_arg(argptr, char *);
	if (str == NULL)
		str = "(null)";
	data->len = ft_strlen(str);
	if (data->len > data->precision && data->dot)
		data->len = data->precision;
	if (data->flag == '-')
	{
		data->width = data->width - data->len;
		data->count += ft_putstr(str, data->len);
		data->count += ft_print_width(data->width, 0, ' ');
	}
	else
	{
		data->width = data->width - data->len;
		data->count += ft_print_width(data->width, 0, ' ');
		data->count += ft_putstr(str, data->len);
	}
}
