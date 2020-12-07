
#ifndef FT_PARSER_H
# define FT_PARSER_H
# include <stdlib.h>
# include <stdio.h> // удоли
# define FLAGS_AND_TYPES	"cspdiuxX-0+# "
# define FLAGS				"-0+# "
# define TYPES				"cspdiuxX"
# define FLG_NONE			0b00000000
# define FLG_MINUS			0b00000001
# define FLG_ZERO			0b00000010
# define FLG_HASH			0b00000100
# define FLG_SPACE			0b00001000
# define FLG_PLUS			0b00010000
# define FLG_ERROR			0b10000000

typedef struct		s_parser
{
	unsigned char	flag;
	int				width;
	int				precision;
	char			type;
	int				size;
	char			c;
	char			*next;
}					t_parser;

char		*find_specifier(char *str);
void		create_struct(t_parser *data);
char		*parse_flags(char *str_after_specifier, t_parser *data);
char		*digit_parse(char *str, t_parser *data, int width);
char		*parse_width(char *str_after_flag, t_parser *data, va_list argptr);
char		*parse_precision(char *str_after_width, t_parser *data,
					   va_list argptr);
char		*parse_size(char *str_after_precision, t_parser *data);
char		*parse_type(char *str_after_size, t_parser *data, va_list argptr);

#endif