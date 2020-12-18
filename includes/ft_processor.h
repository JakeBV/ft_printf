
#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

char	*processor(char *str, t_parser *data, va_list argptr);
void	what_is_it(t_parser *data, va_list argptr);

int	print_width_and_precision(int width_or_precision, int i, char symbol);

void	print_c(t_parser *data, va_list argptr);
void	ft_putchr(char c);
void	print_s(t_parser *data, va_list argptr);
void	ft_putstr(char *str, size_t len);
void 	print_nbr(t_parser *data, va_list argptr);
void 	print_d(t_parser *data, va_list argptr);
void	ft_putnbr(int n);
int		digit_len(int n);

void	digits_proccesors(t_parser *data, int nbr, int negative, int len);

#endif
