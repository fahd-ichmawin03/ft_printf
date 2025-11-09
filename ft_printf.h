
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putnbr(long number, int count);
int	ft_putunbr(unsigned int number, int count);
int	ft_putchar(int c);
int	ft_putnbr_hexa(unsigned int n, int cap);
int	ft_print_ptr(unsigned long long number, int count);
int	ft_ptr(unsigned long long ptr, int count);

#endif
