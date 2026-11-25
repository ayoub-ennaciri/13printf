/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:20:45 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:10:41 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	calc_num_base(int base, long num, t_format *ptr)
{
	int	s;

	s = 0;
	if (!num)
		return (0);
	if (base == 10 && num < 0 && !ptr->precesion)
	{
		s = 1;
		num = -num;
	}
	if (base == 16 && num < 0)
		return (calc_num_base(base,
				((unsigned int) num) / base, ptr) + 1);
	else if (num)
		return (calc_num_base(base, num / base, ptr) + 1 + s);
	return (1);
}

int	p_calc_num_base(unsigned long num, t_format *ptr)
{
	if (!num)
		return (0);
	if (num >= 16)
		return (p_calc_num_base(((unsigned long) num / 16), ptr) + 1);
	return (1);
}

int	calculat_lenght(t_format *ptr, void *var)
{
	int	var_len;

	if (ptr->type == 'd' || ptr->type == 'i')
		var_len = calc_num_base(10, *((int *)var), ptr);
	if (ptr->type == 'u')
		var_len = calc_num_base(10, *((unsigned int *)var), ptr);
	if (ptr->type == 'x' || ptr->type == 'X')
		var_len = calc_num_base(16, *((unsigned long *)var), ptr);
	if (ptr->type == 'p')
		var_len = p_calc_num_base(*((unsigned long *)var), ptr);
	if (ptr->type == 's')
		var_len = ft_strlen((char *)var);
	if (ptr->type == 'c')
		var_len = 0;
	return (var_len);
}

static void	save(t_format *ptr, int len)
{
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
}

int	calculat_width_lenght(t_format *ptr, void *var)
{
	int	len;

	len = calculat_lenght(ptr, var);
	if (ptr->type == 'd' || ptr->type == 'i' || ptr->type == 'u')
	{
		if ((ptr->precesion && *(int *)var < 0)
			|| ((ptr->plus || ptr->space) && *(int *)var >= 0)
			|| (!ptr->precesion && !*(int *)var))
			ptr->width--;
	}
	if (!*(unsigned long *)var && (ptr->type == 'p'))
		ptr->width -= 5;
	if (((*(unsigned long *)var && (ptr->type == 'p')) || (*(int *)var
				&& (((ptr->type == 'x' || ptr->type == 'X')) && ptr->hash))))
		ptr->width -= 2;
	if (!*(int *)var && ((ptr->type == 'x' || ptr->type == 'X')))
		ptr->width--;
	save(ptr, len);
	if (ptr->type != 's' && ptr->precesion)
		ptr->lenght = ptr->lenght - len;
	if (ptr->lenght < 0)
		ptr->lenght = 0;
	if (ptr->width < 0)
		ptr->width = 0;
	return (ptr->width);
}
