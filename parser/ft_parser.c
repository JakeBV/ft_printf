#include "../includes/ft_parser.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_processor.h"

char	*parse_flags(char *str_after_specifier, t_parser *data)
{
	if (ft_strchr(FLAGS, *str_after_specifier))
	{
		data->flag = *str_after_specifier;
		str_after_specifier++;
	}
	return (str_after_specifier);
}

char	*digit_parse(char *str, t_parser *data, int width)
{
	int n;

	if (ft_strchr(DIGITS, *str))
	{
		n = ft_atoi(str);
		if (width)
			data->width = n;
		else
			data->precision = n;
		while (ft_strchr(DIGITS, *str))
			str++;
	}
	return (str);
}

char	*parse_width(char *str_after_flag, t_parser *data, va_list argptr)
{
	if (*str_after_flag == '*')
	{
		data->width = va_arg(argptr, int);
		str_after_flag++;
	}
	else
		str_after_flag = digit_parse(str_after_flag, data, 1);
	return (str_after_flag);
}

char	*parse_precision(char *str_after_width, t_parser *data, va_list argptr)
{
	int point;

	point = 0;
	if (*str_after_width == '.' && *(str_after_width + 1) == '*')
	{
		data->precision = va_arg(argptr, int);
		str_after_width += 2;
		point = 1;
	}
	else if (*str_after_width == '.')
	{
		str_after_width = digit_parse(++str_after_width, data, 0);
		point = 1;
	}
	data->point = point;
	return (str_after_width);
}

char	*parse_type(char *str_after_precision, t_parser *data)
{
	if (*str_after_precision == 'c')
		data->type = 'c';
	else if (*str_after_precision == 's')
		data->type = 's';
	else if (*str_after_precision == 'd' || *str_after_precision == 'i')
		data->type = 'd';
	return (str_after_precision);
}
