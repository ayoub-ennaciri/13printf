#include "../include/ft_printf.h"

void	handle_c(char c, format *ptr)
{
	if (ptr->minus)
	{
		ft_putchar(c);
		handle_space(ptr->width - 1);
	}
	else
	{
		handle_space(ptr->width - 1);
		ft_putchar(c);
	}
}