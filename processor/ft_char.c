#include "../includes/ft_parser.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_processor.h"

void	print_c(t_parser *data, va_list argptr)
{
	int i;

	if (data->width < 0)
		data->width *= -1;
	if (data->flag == '-')
	{
		ft_putchr(va_arg(argptr, int));
		i = print_width_and_precision(data->width, 1, ' ');
	}
	else
	{
		i = print_width_and_precision(data->width, 1, ' ');
		ft_putchr(va_arg(argptr, int));
	}
	data->count += i;
}

void	ft_putchr(char c)
{
	write(1, &c, 1);
}
