#include "../includes/ft_parser.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_processor.h"

int	print_width_and_precision(int width_or_precision, int i, char symbol)
{
	while (--width_or_precision > 0)
	{
		ft_putchr(symbol);
		i++;
	}
	return (i);
}