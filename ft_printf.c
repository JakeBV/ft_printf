/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:30:39 by mstoneho          #+#    #+#             */
/*   Updated: 2020/11/24 18:30:41 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"
#include "includes/ft_parser.h"
#include "includes/ft_processor.h"


void		create_struct(t_parser *data)
{
	data->flag = 0;
	data->width = 0;
	data->precision = 0;
	data->count = 0;
}


int		ft_printf(const char *text, ...)
{
	va_list	argptr;
	t_parser data;

	va_start(argptr, text);
	create_struct(&data);
	while (*text)
	{
		if (*text != '%')
		{
			ft_putchr(*text);
			data.count++;
		}
		else
		{
			text = processor((char *) text, &data, argptr);
		}
		text++;
	}
	va_end(argptr);
	return (data.count);
}