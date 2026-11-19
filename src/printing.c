#include "../include/ft_printf.h"
#include "../include/libft.h"

int ft_putchar(int c)
{
	write(1, (unsigned char *)&c, 1);
	return 1;
}

void	handle_zero(int	len)
{
	while (len-- > 0)
		ft_putchar('0');	
}

void	handle_space(int	len)
{
	while (len-- > 0)
		ft_putchar(' ');
}

int	ft_putstr(char *str, size_t	len)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (i >= len)
			break;
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_put_nbr_base(char *base, long num,long base_len)
{
	if (base_len == 10 && num < 0)
		num = -num;
	if (base_len == 16 && num < 0 && num >= base_len)
		ft_put_nbr_base(base, ((unsigned int) num) / base_len, base_len);
	else if (num >= base_len)
		ft_put_nbr_base(base, num / base_len, base_len);
	write(1, &base[num % base_len], 1);
}


