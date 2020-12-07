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

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

int		ft_printf(const char *text, ...)
{
	va_list	argptr;
	int		i;
	char	*s;
	t_parser data;


	va_start(argptr, text);
	i = 0;
	while (*text)
	{
		if (*text != '%')
			ft_putchr(*text);
		else
		{
			create_struct(&data);
			s = find_specifier((char *)text);
			s = parse_flags(s, &data);
			s = parse_width(s, &data, argptr);
			s = parse_precision(s, &data, argptr);
			s = parse_size(s, &data);
			s = parse_type(s, &data, argptr);
			printf("flag == %c, width == %d, precision == %d, type == %c, size == %d, content == %c\n\n%s\n\n",
		  data.flag, data.width, data.precision, data.type, data.size, data.c, s);
		}
		i++;
		text++;
	}
	va_end(argptr);
	return (i);
}