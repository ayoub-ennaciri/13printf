#include "../include/ft_printf.h"
#include "../include/printing.h"

int	handle_c(char c, format *ptr)
{
	if (ptr->minus)
	{
		ft_putchar(c, ptr);
		handle_space(ptr->width - 1, ptr);
	}
	else
	{
		handle_space(ptr->width - 1, ptr);
		ft_putchar(c, ptr);
	}
	return (1);
}