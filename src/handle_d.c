#include "../include/ft_printf.h"

int	handle_d(long num, format *ptr)
{
	int	len;
	int tmp;
	//int nbr;

	tmp = 0;
	len = calc_num_base(10, num);
	
	if (ptr->lenght_act && len < ptr->lenght)
		tmp = ptr->lenght;
	else
		tmp = len;
	if (ptr->plus || ptr->space)
		tmp += 1;
	if (ptr->width_act)
	{
		if(tmp < ptr->width)
			ptr->width = ptr->width - tmp;
		else
			ptr->width = 0;
	}
	if (ptr->minus)
	{
		if (ptr->plus && num >= 0)
			ft_putchar('+');
		ft_put_nbr_base("012345689", num, ft_strlen("012345689"));
		handle_space(ptr->width);
	}
	else
	{
		if (ptr->width_act)
		{
			if (ptr->zero && !ptr->lenght_act)
				handle_zero(ptr->width);
			else 
				handle_space(ptr->width);
			if (ptr->lenght_act)
				handle_zero(tmp - len);
		}
		if (ptr->plus && num >= 0)
			ft_putchar('+');
		ft_put_nbr_base("0123456789", num, ft_strlen("0123456789"));
	}
	return 1;
}

//int	handle_d(long num, format *ptr)
//{
//	width(ptr, num);

//	if ()
//}
