#include "../includes/ft_parser.h"
#include "../includes/libft.h"

char		*find_specifier(char *str)
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