#include "../includes/ft_parser.h"
#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include "../includes/ft_processor.h"

void	print_s(t_parser *data, va_list argptr)
{
	char	*str;
	size_t	len;
	int 	i;

	str = va_arg(argptr, char *);
	len = ft_strlen(str);
	if (data->precision > 0 && data->precision < (int)len)
		len = len - (len - data->precision);
	if (data->width < 0)
	{
		data->width *= -1;
		data->flag = '-';
	}
	data->width = data->width - (int)len + 1;
	if (data->flag == '-')
	{
		ft_putstr(str, len);
		i = print_width_and_precision(data->width, 0, ' ');
	}
	else
	{
		i = print_width_and_precision(data->width, 0, ' ');
		ft_putstr(str, len);
	}
	data->count += (int)len + i;
}

void	ft_putstr(char *str, size_t len)
{
	while (len)
	{
		ft_putchr(*str++);
		len--;
	}
}
