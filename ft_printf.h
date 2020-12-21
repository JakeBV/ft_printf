/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:04:12 by mstoneho          #+#    #+#             */
/*   Updated: 2020/12/20 20:04:13 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_FT_PRINTF_FT_PRINTF_H
# define NEW_FT_PRINTF_FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define FLAGS_AND_TYPES	"cspdiuxX%-0.*"
# define FLAGS				"-0"
# define DIGITS				"-0123456789"
# define HEXUP				"0123456789ABCDEF"
# define HEXDOWN				"0123456789abcdef"

typedef struct		s_ft_printf
{
	char			flag;
	char			type;
	int				width;
	int				precision;
	int				point;
	int				count;
}					t_ft_printf;

int					ft_printf(const char *text, ...);
int					ft_putstr(char *str, int len);
int					ft_putnbr(unsigned int n);
int					ft_digit_len(unsigned int n, int numsys);
int					print_width_and_precision(int width_or_precision, int i,
										char symbol);
long long int		ft_atoi(char *str);
size_t				ft_strlen(const char *str);
char				*ft_parse_flags(char *str_after_specifier,
										t_ft_printf *data);
char				*ft_digit_parse(char *str, t_ft_printf *data, int width);
char				*ft_parse_width(char *str_after_flag, t_ft_printf *data,
										va_list argptr);
char				*ft_parse_precision(char *str_after_width,
										t_ft_printf *data, va_list argptr);
char				*ft_parse_type(char *str_after_precision,
										t_ft_printf *data);
char				*ft_parser(char *str, t_ft_printf *data, va_list argptr);
char				*ft_find_specifier(char *str);
char				*ft_strchr(const char *s, int c);
void				ft_processor(t_ft_printf *data, va_list argptr);
void				ft_fill_struct(t_ft_printf *data, int count);
void				ft_putchar(int c);

void				ft_print_char(t_ft_printf *data, va_list argptr);
void				ft_print_string(t_ft_printf *data, va_list argptr);
void				ft_print_digit(t_ft_printf *data, va_list argptr);
void				ft_digits_processor(t_ft_printf *data,
								unsigned int nbr, int len, int negative);
void				ft_minus_digit(t_ft_printf *data, unsigned long int nbr,
										int len, int negative);
void				ft_zero_digit(t_ft_printf *data, unsigned int nbr,
										int len, int negative);
void				ft_print_unsigned(t_ft_printf *data, va_list argptr);
void				ft_print_hex(t_ft_printf *data, va_list argptr);
void				ft_puthex(t_ft_printf *data, unsigned int nbr,
										unsigned int nbrcpy);
void				ft_negative_processor(t_ft_printf *data, int negative);
void				ft_print_processor(t_ft_printf *data, unsigned long int nbr);
void				ft_width_processor(t_ft_printf *data, int len);

#endif
