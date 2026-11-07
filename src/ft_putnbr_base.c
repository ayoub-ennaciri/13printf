#include "../include/ft_printf.h"

void	ft_put_nbr_base(char *base, long num,size_t base_len)
{
	if (!num)
	{
			
		return;
	}
	if (base_len == 10 && num < 0)
		num = -num;
	if (base_len == 16 && num < 0)
		ft_put_nbr_base(base, ((unsigned int) num) / base_len, base_len);
	else
		ft_put_nbr_base(base, num / base_len, base_len);
	write(1, &base[num % base_len], 1);
}
