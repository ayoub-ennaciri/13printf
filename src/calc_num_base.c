#include "../include/ft_printf.h"

int	calc_num_base(int base, long num)
{
	int s;

	s = 0;
	if (!num)
		return (0);
	if (base == 10 && num < 0)
	{
		s = 1;
		num =  -num;
	}

	return (calc_num_base(base, num / base) + 1 + s);
}
