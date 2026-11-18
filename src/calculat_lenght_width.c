#include "../include/ft_printf.h"

int	calculat_lenght(format *ptr, void *var)
{
	int var_len;
	
	if (ptr->type == 'd' || ptr->type == 'i')
		var_len = calc_num_base(10, *((int *)var));
	if (ptr->type == 'u')
		var_len = calc_num_base(10, *((unsigned int *)var));
	if (ptr->type == 'x' || ptr->type == 'X' || ptr->type == 'P')
		var_len = calc_num_base(16, *((int *)var));
	if (ptr->type == 's')
		var_len = ft_strlen((char *)var);
	if (ptr->type == 'c')
		var_len = 0;
	if (ptr->precesion && (ptr->lenght = ptr->lenght - var_len) < 0)
		ptr->lenght = 0;
	return (ptr->lenght);
}

int calculat_width_lenght(format *ptr, void *var)
{
	if (ptr->space)
		ptr->width--;
	if (ptr->width_act && (ptr->width = ptr->width - calculat_lenght(ptr, var)) < 0)
		ptr->width = 0;
	return (ptr->width);
}