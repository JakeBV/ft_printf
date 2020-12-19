#include "ft_printf.h"
#include "libft/libft.h"

char 	*ft_parser(char *str, t_ft_printf *data, va_list argptr)
{
	str = ft_find_specifier(str);
	str = ft_parse_flags(str, data);
	str = ft_parse_width(str, data, argptr);
	str = ft_parse_precision(str, data, argptr);
	str = ft_parse_type(str, data);
	return (str);
}

//void 	ft_processor(t_ft_printf *data, va_list argptr)
//{
//	if (data->type == 'c')
//		(data, argptr);
//}

char	*ft_find_specifier(char *str)
{
	while (*str)
	{
		if (*str == '%' && (ft_strchr(FLAGS_AND_TYPES, *(str + 1)) ||
							ft_strchr(DIGITS, *(str + 1))))
			return (++str);
		if (*str == '%' && *(str + 1) == '%')
			str++;
		str++;
	}
	return (NULL);
}

int		ft_printf(const char *text, ...)
{
	va_list		argptr;
	t_ft_printf	data;

	va_start(argptr, text);
	ft_fill_struct(&data, 0);
	while (*text)
	{
		if (*text != '%')
		{
			ft_putchar(*text);
			data.count++;
		}
		else
		{
			text = ft_parser((char *) text, &data, argptr);
		}
		text++;
	}
	va_end(argptr);
	return (data.count);
}