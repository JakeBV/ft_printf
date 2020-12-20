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
	int		len;
	char	*str;

	str = va_arg(argptr, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (data->precision > 0 && len > data->precision)
		len = data->precision;
	if (data->flag == '-')
	{
		data->width = data->width - len;
		data->count += ft_putstr(str, len);
		data->count += print_width_and_precision(data->width, 0, ' ');
	}
	else
	{
		data->width = data->width - len;
		data->count += print_width_and_precision(data->width, 0, ' ');
		data->count += ft_putstr(str, len);
	}
}
