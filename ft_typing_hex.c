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
	unsigned long int	nbr;
	int					len;

	nbr = va_arg(argptr, unsigned long int);
	len = ft_digit_len(nbr, 16);
	ft_digits_processor(data, nbr, len, 0);
}
