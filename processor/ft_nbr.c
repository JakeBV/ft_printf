#include "../includes/ft_parser.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_processor.h"


void 	print_d(t_parser *data, va_list argptr)
{
	int len;
	int nbr;
	int negative;

	negative = 0;
	nbr = va_arg(argptr, int);
	if (nbr < 0)
	{
		negative = 1;
		nbr = -nbr;
	}
	len = digit_len(nbr);
	if (negative)
		len++;
	digits_proccesors(data, nbr, negative, len);
}

int		digit_len(int n)
{
	if (n < 10)
		return (1);
	return (1 + digit_len(n / 10));
}

void	ft_putnbr(int n)
{
	char d;

	d = n % 10 + '0';
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchr(d);
}
