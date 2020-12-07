#include "../includes/ft_parser.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void		create_struct(t_parser *data)
{
	data->flag = 0;
	data->width = 0;
	data->precision = 0;
	data->size = 0;
	data->next = NULL;
}

char		*find_specifier(char *str)
{
	while (*str)
	{
		if (*str == '%' && ft_strchr(FLAGS_AND_TYPES, *(str + 1)))
			return (++str);
		if (*str == '%' && *(str + 1) == '%')
			str++;
		str++;
	}
	return (NULL);
}

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

	if (ft_strchr("0123456789", *str))
	{
		n = ft_atoi(str);
		if (width)
			data->width = n;
		else
			data->precision = n;
		while (ft_strchr("0123456789", *str))
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
	if (*str_after_width == '.' && *(str_after_width + 1) == '*')
	{
		data->precision = va_arg(argptr, int);
		str_after_width += 2;
	}
	else if (*str_after_width == '.')
		str_after_width = digit_parse(++str_after_width, data, 0);
	return (str_after_width);
}

char	*parse_size(char *str_after_precision, t_parser *data)
{
	if (*str_after_precision == 'l' && *(str_after_precision + 1) == 'l')
	{
		data->size = 1;
		str_after_precision += 2;
	}
	else if (*str_after_precision == 'l')
	{
		data->size = 2;
		str_after_precision++;
	}
	else if (*str_after_precision == 'h' && *(str_after_precision + 1) == 'h')
	{
		data->size = 3;
		str_after_precision += 2;
	}
	else if (*str_after_precision == 'h')
	{
		data->size = 4;
		str_after_precision++;
	}
	return (str_after_precision);
}

char	*parse_type(char *str_after_size, t_parser *data, va_list argptr)
{
	if (*str_after_size == 'c')
	{
		data->type = 'c';
		data->c = va_arg(argptr, int);
	}
	return (++str_after_size);
}
