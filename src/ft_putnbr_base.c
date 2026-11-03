#include "../include/ft_printf.h"

void	ft_put_nbr_base(char *base, long num,size_t base_len)
{
	if (!num)
		return;
	if (ft_strlen(base) == 10 && num < 0)
		num = -num;
	ft_put_nbr_base(base, num / base_len, base_len);
	write(1, &base[num % base_len], 1);
}
