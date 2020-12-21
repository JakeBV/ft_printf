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
	int						len;

	nbr = va_arg(argptr, unsigned long long int);
	len = ft_digit_len(nbr, 16);
	if (data->type == 'p')
	{
		data->pointer = nbr;
		len = ft_hex_len(data->pointer);
	}
	ft_digits_processor(data, nbr, len, 0);
}

int		ft_hex_len(unsigned long long int n)
{
	if (n < 16)
		return (1);
	return (1 + ft_hex_len(n / 16));
}
