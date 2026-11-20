#ifndef	CALCULATIONS_H
# define	CALCULATIONS_H

#include "libft.h"

int		handle_zero(int	len);
int		handle_space(int len);
int		ft_putstr(char *str, format *ptr);
int		ft_put_nbr_base(int printed_len, char *base, long num,long base_len);
int		ft_putchar(int c);

#endif