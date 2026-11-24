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
		if (*copy == '%')
		{
			if ((tmp_len = manage_form_specifiers(&copy, &args))== -1)
				return (-1);
			len += tmp_len;
		}
		else
		{
			if (write(1, copy, 1) == -1)
				return (-1);
			copy++;
			len++;
		}
	}
	va_end(args);
	return (len);
}