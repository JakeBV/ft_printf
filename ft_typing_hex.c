/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:45:09 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:45:10 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(t_ft_printf *data, va_list argptr)
{
	unsigned long long int	nbr;

	nbr = va_arg(argptr, unsigned long long int);
	if (data->type == 'p')
	{
		data->width -= 2;
		data->pointer = nbr;
		data->len = ft_hex_len(data->pointer);
	}
	else
	{
		data->len = ft_digit_len(nbr, 16);
		data->digit = nbr;
	}
	ft_digits_processor(data);
}

int		ft_hex_len(unsigned long long int n)
{
	if (n < 16)
		return (1);
	return (1 + ft_hex_len(n / 16));
}
