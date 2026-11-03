#include "../include/ft_printf.h"

void	handle_space(size_t	len)
{
	while (len-- > 0)
		ft_putchar(' ');
}