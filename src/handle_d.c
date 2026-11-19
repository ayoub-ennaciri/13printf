/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:33:58 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/19 16:47:41 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"
#include "../include/calculations.h"

static void handle_left(long num, format *ptr)
{
	if (num < 0)
				ft_putchar('-');
		else if (num >= 0 && ptr->plus)
			ft_putchar('+');
		else if (num >= 0 && ptr->space)
			ft_putchar(' ');		
		if (!ptr->precesion)
		{
		}
		if (ptr->precesion)
			handle_zero(ptr->lenght);
		if(!(ptr->precesion  && !num))
			ft_put_nbr_base(BASE_10, num, ft_strlen(BASE_10));
		handle_space(ptr->width);
}
static void handle_right(long num, format *ptr)
{
	if (!ptr->precesion && ptr->zero)
	{
		if (num < 0)
		ft_putchar('-');
		else if (num >= 0 && ptr->plus)
			ft_putchar('+');
		else if (num >= 0 && ptr->space)
		ft_putchar(' ');		
		handle_zero(ptr->width);
	}
	else
	{
		handle_space(ptr->width);
		if (num < 0)
		ft_putchar('-');
		else if (num >= 0 && ptr->plus)
			ft_putchar('+');
		else if (num >= 0 && ptr->space)
		ft_putchar(' ');		
	}
	
	if (ptr->precesion)
		handle_zero(ptr->lenght);
	if(!(ptr->precesion && !num))
		ft_put_nbr_base(BASE_10, num, ft_strlen(BASE_10));
}

int	handle_d(long num, format *ptr)
{
	calculat_width_lenght(ptr, &num);
	if (ptr->minus)
		handle_left(num, ptr);
	else
		handle_right(num, ptr);
		return (0);
}