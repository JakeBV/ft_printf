#include "ft_printf.h"

void	ft_fill_struct(t_ft_printf *data, int count)
{
	data->flag = 0;
	data->width = 0;
	data->precision = 0;
	data->count = count;
}
