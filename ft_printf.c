/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:03:48 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:04:03 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parser(char *str, t_ft_printf *data, va_list argptr)
{
	str = ft_find_specifier(str);
	str = ft_parse_flags(str, data);
	str = ft_parse_width(str, data, argptr);
	str = ft_parse_precision(str, data, argptr);
	str = ft_parse_type(str, data);
	if (data->width < 0)
	{
		data->width = -data->width;
		data->flag = '-';
	}
	ft_processor(data, argptr);
	ft_fill_struct(data, data->count);
	return (str);
}

void	ft_processor(t_ft_printf *data, va_list argptr)
{
	if (data->type == 'c' || data->type == '%')
		ft_print_char(data, argptr);
	else if (data->type == 's')
		ft_print_string(data, argptr);
	else if (data->type == 'd')
		ft_print_digit(data, argptr);
	else if (data->type == 'u')
		ft_print_unsigned(data, argptr);
	else if (data->type == 'x' || data->type == 'X' || data->type == 'p')
		ft_print_hex(data, argptr);
}

char	*ft_find_specifier(char *str)
{
	while (*str)
	{
		if (*str == '%' && (ft_strchr(FLAGS_AND_TYPES, *(str + 1)) ||
							ft_strchr(DIGITS, *(str + 1))))
			return (++str);
		str++;
	}
	return (NULL);
}

int		ft_printf(const char *text, ...)
{
	va_list		argptr;
	t_ft_printf	data;

	va_start(argptr, text);
	ft_fill_struct(&data, 0);
	while (*text)
	{
		if (*text != '%')
		{
			ft_putchar(*text);
			data.count++;
		}
		else
			text = ft_parser((char *)text, &data, argptr);
		text++;
	}
	va_end(argptr);
	return (data.count);
}
