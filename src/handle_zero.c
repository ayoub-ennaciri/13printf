#include "../include/ft_printf.h"

void	handle_zero(int	len)
{
	while (len-- > 0)
		ft_putchar('0');	
}