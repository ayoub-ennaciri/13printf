#include "../include/ft_printf.h"
#include "../include/libft.h"

int ft_putchar(int c, format *ptr)
{
	if (ptr->error)
		return (0);
	if (write(1, (unsigned char *)&c, 1) == -1)
	{
		ptr->error = 1;
		return (0);
	}
	return (1);
}

int	handle_zero(int	len, format *ptr)
{
	int i;

	if (ptr->error)
		return (0);
	i = 0;
	while (i < len)
	{
		if (ft_putchar('0', ptr) == -1)
			return (0);
		i++;
	}
	return (i);
}

int	handle_space(int len, format *ptr)
{
	int i;

	if (ptr->error)
		return (0);
	i = 0;
	while (i < len)
	{
		if (ft_putchar(' ', ptr) == -1)
			return (0);
		i++;
	}
	return (i);
}

int	ft_putstr(char *str, format *ptr)
{
	int	i;

	if (ptr->error)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ptr->precesion && i >= ptr->lenght)
			break;
		if (ft_putchar(str[i], ptr) == -1)
			return (0);
		i++;
	}
	return (i);
}

int	p_ft_put_nbr_base(int printed_len, char *base, unsigned long num, format *ptr)
{	
	if (num >= 16)
	printed_len += p_ft_put_nbr_base(printed_len, base, num / 16, ptr);
	write(1, &base[num % 16], 1);
	return (++printed_len);
}

int	ft_put_nbr_base(int printed_len, char *base, long num,long base_len, format *ptr)
{
	if (ptr->error)
		return (0);
	if (ptr->type == 'p')
		return (p_ft_put_nbr_base(printed_len, base, (unsigned long) num, ptr));
	if (base_len == 10 && num < 0)
		num = -num;
	if (base_len == 16 && num < 0)
		printed_len += ft_put_nbr_base(printed_len, base, ((unsigned long) num) / base_len, base_len, ptr);
	else if (num >= base_len)
		printed_len += ft_put_nbr_base(printed_len, base, num / base_len, base_len, ptr);
	write(1, &base[num % base_len], 1);
	return (++printed_len);
}

