#include "../include/ft_printf.h"

int ft_printf(const char *s, ...)
{
	char *copy;
	va_list	args;
	va_start(args,s);

	copy = (char *)s;
	while (*copy)
	{
		if (*copy == '%' && manage_form_specifiers(&copy, &args));
		else
		{
			ft_putchar(*copy);
			copy++;
		}
	}
	
	va_end(args);
	return (0);
}