/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:33:58 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:10:46 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"
#include "../include/calculations.h"

static void	handle_left(long num, t_format *ptr)
{
	if (num < 0)
		ptr->total_length += ft_putchar('-', ptr);
	else if (num >= 0 && ptr->plus && (ptr->type == 'd' || ptr->type == 'i'))
		ptr->total_length += ft_putchar('+', ptr);
	else if (num >= 0 && ptr->space && (ptr->type == 'd' || ptr->type == 'i'))
		ptr->total_length += ft_putchar(' ', ptr);
	if (ptr->precesion)
		ptr->total_length += handle_zero(ptr->lenght, ptr);
	if (!ptr->precesion || num)
		ptr->total_length += ft_put_nbr_base(BASE_10, num,
				ft_strlen(BASE_10), ptr);
	ptr->total_length += handle_space(ptr->width, ptr);
}

static void	handle_right(long num, t_format *ptr)
{
	if (ptr->precesion || !ptr->zero)
		ptr->total_length += handle_space(ptr->width, ptr);
	if (num < 0)
		ptr->total_length += ft_putchar('-', ptr);
	else if (num >= 0 && ptr->plus
		&& (ptr->type == 'd' || ptr->type == 'i'))
		ptr->total_length += ft_putchar('+', ptr);
	else if (num >= 0 && ptr->space
		&& (ptr->type == 'd' || ptr->type == 'i'))
		ptr->total_length += ft_putchar(' ', ptr);
	if (!ptr->precesion && ptr->zero)
		ptr->total_length += handle_zero(ptr->width, ptr);
	if (ptr->precesion)
		ptr->total_length += handle_zero(ptr->lenght, ptr);
	if (!ptr->precesion || num)
		ptr->total_length += ft_put_nbr_base(BASE_10,
				num, ft_strlen(BASE_10), ptr);
}

int	handle_d(long num, t_format *ptr)
{
	calculat_width_lenght(ptr, &num);
	if (ptr->minus)
		handle_left(num, ptr);
	else
		handle_right(num, ptr);
	return (ptr->total_length);
}
