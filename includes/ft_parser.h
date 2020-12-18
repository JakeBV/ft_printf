
#ifndef FT_PARSER_H
# define FT_PARSER_H
# include <stdlib.h>
# include <stdio.h> // удоли
# define FLAGS_AND_TYPES	"cspdiuxX-0.*"
# define FLAGS				"-0"
# define DIGITS				"-0123456789"


typedef struct		s_parser
{
	unsigned char	flag;
	int				width;
	int				precision;
	char			type;
	int 			count;
	int 			point;
}					t_parser;

char		*find_specifier(char *str);
void		create_struct(t_parser *data);
char		*parse_flags(char *str_after_specifier, t_parser *data);
char		*digit_parse(char *str, t_parser *data, int width);
char		*parse_width(char *str_after_flag, t_parser *data, va_list argptr);
char		*parse_precision(char *str_after_width, t_parser *data,
					   va_list argptr);
char		*parse_type(char *str_after_precision, t_parser *data);

#endif