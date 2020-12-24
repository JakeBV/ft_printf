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
# define ALL				"cspdiuxX%-0123456789.*"
# define DIGITS				"-0123456789"
# define HEX_UP				"0123456789ABCDEF"
# define HEX_DOWN			"0123456789abcdef"

typedef struct				s_ft_printf
{
	char					flag;
	char					type;
	int						width;
	int						precision;
	int						dot;
	int						len;
	int						is_negative;
	int						count;
	unsigned int			digit;
	unsigned long long int	pointer;
}							t_ft_printf;

int							ft_printf(const char *text, ...);
int							ft_putstr(char *str, int len);
int							ft_putnbr(unsigned int n);
int							ft_digit_len(unsigned int n, unsigned int numsys);
int							ft_hex_len(unsigned long long int n);
int							ft_print_width(int width, int i, char symbol);
long long int				ft_atoi(const char *str);
size_t						ft_strlen(const char *str);
char						*ft_parse_flags(char *str_after_specifier,
									t_ft_printf *data);
char						*ft_digit_parse(char *str, t_ft_printf *data,
											int width);
char						*ft_parse_width(char *str_after_flag,
											t_ft_printf *data, va_list argptr);
char						*ft_parse_precision(char *str_after_width,
											t_ft_printf *data, va_list argptr);
char						*ft_parser(char *str, t_ft_printf *data,
											va_list argptr);
char						*ft_strchr(const char *s, int c);
char						*ft_processor(char *str_after_precision,
											t_ft_printf *data, va_list argptr);
void						ft_fill_struct(t_ft_printf *data, int count);
void						ft_putchar(int c);
void						ft_print_char(t_ft_printf *data, va_list argptr);
void						ft_print_string(t_ft_printf *data, va_list argptr);
void						ft_print_digit(t_ft_printf *data, va_list argptr);
void						ft_digits_processor(t_ft_printf *data);
void						ft_minus_digit(t_ft_printf *data);
void						ft_zero_digit(t_ft_printf *data);
void						ft_print_unsigned(t_ft_printf *data,
											va_list argptr);
void						ft_print_hex(t_ft_printf *data, va_list argptr);
void						ft_puthex(t_ft_printf *data,
											unsigned long long int nbr,
											unsigned long long int nbrcpy);
void						ft_negative_processor(t_ft_printf *data);
void						ft_print_processor(t_ft_printf *data);
void						ft_width_processor(t_ft_printf *data);

#endif
