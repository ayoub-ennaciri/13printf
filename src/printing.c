#include "../include/ft_printf.h"
#include "../include/libft.h"

int ft_putchar(int c)
{
	write(1, (unsigned char *)&c, 1);
	return (1);
}

int	handle_zero(int	len)
{
	int i;

	i = 0;
	while (i++ < len)
		ft_putchar('0');	
	return (i);
}

int	handle_space(int	len)
{
	int i;

	i = 0;
	while (i++ < len)
		ft_putchar(' ');
	return (i);
}

int	ft_putstr(char *str, format *ptr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ptr->precesion && i >= ptr->lenght)
			break;
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_put_nbr_base(int printed_len, char *base, long num,long base_len)
{
	if (base_len == 10 && num < 0)
		num = -num;
	if (base_len == 16 && num < 0 && num >= base_len)
		printed_len += ft_put_nbr_base(printed_len, base, ((unsigned int) num) / base_len, base_len);
	else if (num >= base_len)
		printed_len += ft_put_nbr_base(printed_len, base, num / base_len, base_len);
	write(1, &base[num % base_len], 1);
	return (++printed_len);
}


#include <stdio.h>

int main()
{
	printf(" |%d| : ",ft_put_nbr_base(0, "0123456789", -2147483647, 10)) ;
	return 0;
}