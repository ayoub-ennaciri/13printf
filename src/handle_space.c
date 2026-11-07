#include "../include/ft_printf.h"

void	handle_space(int	len)
{
	while (len-- > 0)
		ft_putchar(' ');
}