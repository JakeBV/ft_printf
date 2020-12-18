#include "../includes/ft_parser.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_processor.h"

void	digits_proccesors(t_parser *data, int nbr, int negative, int len)
{
	int i;

	if (data->width < data->precision)
	{
		data->precision = data->precision - len + 1;
		if (data->flag == '0')
		{
			data->count += print_width_and_precision(data->width - data->precision - 1, 0, ' ');
		}
		if (negative)
		{
			ft_putchr('-');
			data->precision++;
		}
		i = print_width_and_precision(data->precision, 0, '0');
		ft_putnbr(nbr);
		if (data->flag == '-')
			data->count += print_width_and_precision(data->width - data->precision, 0, ' ');
		data->count += i + len;
	}
	else
	{
		data->width = data->width - len;
		if (data->flag == '0') {
			data->count += print_width_and_precision(
					data->width - data->precision - 1, 0, ' ');
		}
		if (negative) {
			ft_putchr('-');
			data->precision++;
		}
		i = print_width_and_precision(data->precision, 0, '0');
		ft_putnbr(nbr);
		if (data->flag == '-')
			data->count += print_width_and_precision(
					data->width - data->precision, 0, ' ');
		data->count += i + len;
	}
}

/*
void	digits_proccesors(t_parser *data, int nbr, int negative, int len)
{
	int		i;
	char 	symbol;

	if (data->width < 0 && data->flag == '-')
		data->width = -data->width;
	if (data->width < 0 && data->flag == '0')
	{
		data->width = -data->width;
		data->flag = '-';
	}
	if (len > data->precision && len > data->width)
	{
		if (negative)
			ft_putchr('-');
		if (data->point && !data->precision && !nbr)
			len = 0;
		else
			ft_putnbr(nbr);
		data->count += len;
	}
	else if (data->flag == '-' && data->precision)
	{
		if (negative)
		{
			ft_putchr('-');
			data->precision++;
		}
		i = print_width_and_precision(data->precision - len + 1, 0, '0');
		ft_putnbr(nbr);
		data->count += i + len;
	}
	else if (data->flag == '-')
	{
		if (negative)
			ft_putchr('-');
		if (data->width)
			data->width = data->width - len + 1;
		ft_putnbr(nbr);
		i = print_width_and_precision(data->width, 0, ' ');
		data->count += i + len;
	}
	else if (data->flag == '0' && data->precision)
	{
		symbol = ' ';
		if (!nbr)
			symbol = '0';
		if (data->width)
			data->width = data->width - len + 1;
		i = print_width_and_precision(data->width, 0, symbol);
		if (negative)
			ft_putchr('-');
		ft_putnbr(nbr);
		data->count += i + len;
	}
	else if (data->flag == '0')
	{
		symbol = '0';
		if (!nbr)
			symbol = ' ';
		if (negative)
			ft_putchr('-');
		if (data->width)
			data->width = data->width - len + 1;
		i = print_width_and_precision(data->width, 0, symbol);
		if (nbr)
			ft_putnbr(nbr);
		else
			ft_putchr(' ');
		data->count += i + len;
	}
}

 	if (data->width < 0)
		data->width = -data->width;
	if (data->flag == '0' && data->precision)
	{
		data->width -= data->precision;
		i = print_width_and_precision(data->width, 1, ' ');
		if (negative)
		{
			ft_putchr('-');
			data->count++;
			data->precision++;
		}
		if (data->precision > len && data->precision > data->width)
			data->precision -= len;
		i += print_width_and_precision(data->precision + 1, 0, '0');
		ft_putnbr(nbr);
		data->count = i + data->count;
*/
