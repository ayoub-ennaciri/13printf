#include "../include/ft_printf.h"
#include "../include/printing.h"


int ft_printf(const char *s, ...)
{
	char *copy;
	va_list	args;
	va_start(args,s);
	int	len;
	int	tmp_len;

	copy = (char *)s;
	len = 0;
	while (*copy)
	{
		if (*copy == '%' && (tmp_len = manage_form_specifiers(&copy, &args)))
			len += tmp_len;
		else
		{
			ft_putchar(*copy);
			copy++;
			len++;
		}
	}
	va_end(args);
	return (len);
}