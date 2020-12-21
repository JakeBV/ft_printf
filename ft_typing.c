/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:04:33 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:04:35 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *str, int len)
{
	int i;

	i = 0;
	while (len > 0 && *str)
	{
		ft_putchar(*str);
		str++;
		len--;
		i++;
	}
	return (i);
}

int		ft_putnbr(unsigned int n)
{
	char	d;
	int		i;

	i = 1;
	d = n % 10 + '0';
	if (n >= 10)
		i += ft_putnbr(n / 10);
	ft_putchar(d);
	return (i);
}

void	ft_puthex(t_ft_printf *data, unsigned int nbr, unsigned int nbrcpy)
{
	unsigned int	mod;
	char			*base;

	base = HEXUP;
	if (data->type == 'x' || data->type == 'p')
		base = HEXDOWN;
	if (nbr >= 10)
	{
		mod = nbr % 16;
		nbr = nbr / 16;
		ft_puthex(data, nbr, nbrcpy);
		ft_putchar(base[mod]);
		data->count++;
	}
	else if (nbr > 0 || !nbrcpy)
	{
		ft_putchar(base[nbr]);
		data->count++;
	}
}

int		print_width_and_precision(int width_or_precision, int i, char symbol)
{
	while (width_or_precision > 0)
	{
		ft_putchar(symbol);
		i++;
		width_or_precision--;
	}
	return (i);
}
