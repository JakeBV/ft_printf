/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:45:28 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:45:29 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_digit_len(unsigned int n, int numsys)
{
	if (n < (unsigned int)numsys)
		return (1);
	return (1 + ft_digit_len(n / numsys, numsys));
}

void			ft_fill_struct(t_ft_printf *data, int count)
{
	data->flag = 0;
	data->width = 0;
	data->precision = 0;
	data->count = count;
}

long long int	ft_atoi(char *str)
{
	int				i;
	int				p;
	long long int	n;

	i = 0;
	n = 0;
	p = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * p);
}

char			*ft_strchr(const char *s, int c)
{
	while (NULL != s && *s)
	{
		if (*(char*)s++ == c)
			return ((char*)--s);
	}
	return (c == '\0' ? (char*)s : NULL);
}

size_t			ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (NULL != str && str[len] != '\0')
		len++;
	return (len);
}
