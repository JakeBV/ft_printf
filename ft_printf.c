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

int		ft_printf(const char *text, ...)
{
	va_list		argptr;
	t_ft_printf	data;

	if (NULL == text)
		return (-1);
	va_start(argptr, text);
	ft_fill_struct(&data, 0);
	while (*text)
	{
		if (*text == '%' && ft_strchr(ALL, *(text + 1)))
			text = ft_parser((char *)++text, &data, argptr);
		else
		{
			ft_putchar(*text);
			data.count++;
		}
		text++;
	}
	va_end(argptr);
	return (data.count);
}
