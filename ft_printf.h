#ifndef NEW_FT_PRINTF_FT_PRINTF_H
# define NEW_FT_PRINTF_FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FLAGS_AND_TYPES	"cspdiuxX-0.*"
# define FLAGS				"-0"
# define DIGITS				"-0123456789"


typedef struct		s_ft_printf
{
	char			flag;
	int				width;
	int				precision;
	int 			point;
	char			type;
	int 			count;
}					t_ft_printf;

char	*ft_parse_flags(char *str_after_specifier, t_ft_printf *data);
char	*ft_digit_parse(char *str, t_ft_printf *data, int width);
char	*ft_parse_width(char *str_after_flag, t_ft_printf *data, va_list argptr);
char	*ft_parse_precision(char *str_after_width, t_ft_printf *data,
							va_list argptr);
char	*ft_parse_type(char *str_after_precision, t_ft_printf *data);
char 	*ft_parser(char *str, t_ft_printf *data, va_list argptr);
char	*ft_find_specifier(char *str);
int		ft_printf(const char *text, ...);
void	ft_fill_struct(t_ft_printf *data, int count);
void	ft_putchar(int c);

#endif
