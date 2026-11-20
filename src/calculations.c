#include "../include/ft_printf.h"

int	calc_num_base(int base, long num, format *ptr)
{
	int s;

	s = 0;
	if (!num)
		return (0);
	if (base == 10 && num < 0 && !ptr->precesion)
	{
		s = 1;
		num =  -num;
	}
	if (base == 16 && num < 0)
		return (calc_num_base(base, ((unsigned int) num) / base, ptr) + 1);
	else if (num)
		return (calc_num_base(base, num / base, ptr) + 1 + s);
	return (0);
}

int	calculat_lenght(format *ptr, void *var)
{
	int var_len;
	
	if (ptr->type == 'd' || ptr->type == 'i')
		var_len = calc_num_base(10, *((int *)var), ptr);
	if (ptr->type == 'u')
		var_len = calc_num_base(10, *((unsigned int *)var), ptr);
	if (ptr->type == 'x' || ptr->type == 'X' || ptr->type == 'P')
		var_len = calc_num_base(16, *((int *)var), ptr);
	if (ptr->type == 's')
		var_len = ft_strlen((char *)var);
	if (ptr->type == 'c')
		var_len = 0;
	return (var_len);
}

int calculat_width_lenght(format *ptr, void *var)
{
	int len;

	len = calculat_lenght(ptr, var);
	if (ptr->type == 'd' || ptr->type == 'i')
	{
		if ((ptr->precesion && *(int *)var < 0) || (( ptr->plus || ptr->space) && *(int *)var >= 0))
			ptr->width--;
		if (!ptr->precesion && !*(int*)var)
			ptr->width--;
	}
	if (*(int*)var && (ptr->type == 'p' || ((ptr->type == 'x' || ptr->type == 'X') && ptr->hash)))
		ptr->width -= 2;
	if (ptr->width)
	{
		if (ptr->type == 's')
		{
			if (ptr->precesion && ptr->lenght < len)
				ptr->width -= ptr->lenght;
			else
				ptr->width -= len;
		}
		else if (ptr->precesion && ptr->lenght && ptr->lenght > len)
			ptr->width -= ptr->lenght;
		else
			ptr->width -= len;
	}
	if (ptr->type != 's' && ptr->precesion && (ptr->lenght = ptr->lenght - len) < 0)
		ptr->lenght = 0;
	if (ptr->width < 0)
		ptr->width = 0;
	return (ptr->width);
}
