/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:03:34 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:03:36 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parser(char *str, t_ft_printf *data, va_list argptr)
{
	str = ft_parse_flags(str, data);
	str = ft_parse_width(str, data, argptr);
	str = ft_parse_precision(str, data, argptr);
	if (data->width < 0)
	{
		data->width = -data->width;
		data->flag = '-';
	}
	if (data->precision < 0)
	{
		data->dot = 0;
		data->precision = 0;
	}
	str = ft_processor(str, data, argptr);
	ft_fill_struct(data, data->count);
	return (str);
}

char	*ft_parse_flags(char *str_after_specifier, t_ft_printf *data)
{
	while (ft_strchr("-0", *str_after_specifier))
	{
		if (*str_after_specifier == '-')
			data->flag = *str_after_specifier;
		if (data->flag == 0 && *str_after_specifier == '0')
			data->flag = '0';
		str_after_specifier++;
	}
	return (str_after_specifier);
}

char	*ft_digit_parse(char *str, t_ft_printf *data, int width)
{
	long long int n;

	if (ft_strchr(DIGITS, *str))
	{
		n = ft_atoi(str);
		if (width)
			data->width = n;
		else
			data->precision = n;
		while (ft_strchr(DIGITS, *str))
			str++;
	}
	return (str);
}

char	*ft_parse_width(char *str_after_flag, t_ft_printf *data, va_list argptr)
{
	if (*str_after_flag == '*')
	{
		data->width = va_arg(argptr, int);
		str_after_flag++;
	}
	else
		str_after_flag = ft_digit_parse(str_after_flag, data, 1);
	return (str_after_flag);
}

char	*ft_parse_precision(char *str_after_width, t_ft_printf *data,
															va_list argptr)
{
	if (*str_after_width == '.' && *(str_after_width + 1) == '*')
	{
		data->precision = va_arg(argptr, int);
		str_after_width += 2;
		data->dot = 1;
	}
	else if (*str_after_width == '.')
	{
		str_after_width = ft_digit_parse(++str_after_width, data, 0);
		data->dot = 1;
	}
	return (str_after_width);
}
