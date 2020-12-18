#include "../includes/ft_parser.h"
#include "../includes/ft_processor.h"
#include "../includes/ft_printf.h"

void print_this_shit(t_parser *data, va_list argptr)
{
	printf("\nflag == %c width == %i precision == %i type == %c content == %c count == %i\n", data->flag, data->width, data->precision, data->type, va_arg(argptr, int), data->count);
}

char		*processor(char *str, t_parser *data, va_list argptr)
{
	str = find_specifier(str);
	str = parse_flags(str, data);
	str = parse_width(str, data, argptr);
	str = parse_precision(str, data, argptr);
	str = parse_type(str, data);
	what_is_it(data, argptr);
	data->flag = 0;
	data->width = 0;
	data->precision = 0;
	data->point = 0;
	return (str);
}

void		what_is_it(t_parser *data, va_list argptr)
{
	if (data->type == 'c')
		print_c(data, argptr);
	else if (data->type == 's')
		print_s(data, argptr);
	else if (data->type == 'd')
		print_d(data, argptr);

}