/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:33:58 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/20 13:08:35 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"
#include "../include/calculations.h"

static void handle_left(long num, format *ptr)
{
	if (num < 0)
			ptr->total_length += ft_putchar('-');
		else if (num >= 0 && ptr->plus)
			ptr->total_length += ft_putchar('+');
		else if (num >= 0 && ptr->space)
			ptr->total_length += ft_putchar(' ');	
		if (ptr->precesion)
			ptr->total_length += handle_zero(ptr->lenght);
		if(!(ptr->precesion  && !num))
			ptr->total_length += ft_put_nbr_base(0, BASE_10, num, ft_strlen(BASE_10));
		ptr->total_length += handle_space(ptr->width);
}
static void handle_right(long num, format *ptr)
{
	if (!ptr->precesion && ptr->zero)
	{
		if (num < 0)
			ptr->total_length += ft_putchar('-');
		else if (num >= 0 && ptr->plus)
			ptr->total_length += ft_putchar('+');
		else if (num >= 0 && ptr->space)
			ptr->total_length += ft_putchar(' ');		
		ptr->total_length += handle_zero(ptr->width);
	}
	else
	{
		ptr->total_length += handle_space(ptr->width);
		if (num < 0)
			ptr->total_length += ft_putchar('-');
		else if (num >= 0 && ptr->plus)
			ptr->total_length += ft_putchar('+');
		else if (num >= 0 && ptr->space)
			ptr->total_length += ft_putchar(' ');		
	}
	
	if (ptr->precesion)
		ptr->total_length += handle_zero(ptr->lenght);
	if(!(ptr->precesion && !num))
		ptr->total_length += ft_put_nbr_base(0, BASE_10, num, ft_strlen(BASE_10));
}

int	handle_d(long num, format *ptr)
{
	calculat_width_lenght(ptr, &num);
	if (ptr->minus)
		handle_left(num, ptr);
	else
		handle_right(num, ptr);
	return (ptr->total_length);
}