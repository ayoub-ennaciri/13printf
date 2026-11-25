/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:33:58 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:10:51 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"
#include "../include/calculations.h"

static void	handle_left(long long num, t_format *ptr, char *base, char *prefix)
{
	if (num && ptr->hash)
		ptr->total_length += write(1, prefix, 2);
	if (ptr->precesion)
		ptr->total_length += handle_zero(ptr->lenght, ptr);
	if (!(ptr->precesion && !num))
		ptr->total_length += ft_put_nbr_base(base,
				(unsigned int) num, ft_strlen(base), ptr);
	ptr->total_length += handle_space(ptr->width, ptr);
}

static void	handle_right(long long num, t_format *ptr, char *base, char *prefix)
{
	if (!(!ptr->precesion && ptr->zero))
		ptr->total_length += handle_space(ptr->width, ptr);
	else
	{
		if (num && ptr->hash)
		{
			ptr->hash = 0;
			write(1, prefix, 2);
		}
		ptr->total_length += handle_zero(ptr->width, ptr);
	}
	if (num && ptr->hash)
		ptr->total_length += write(1, prefix, 2);
	if (ptr->precesion)
	{
		ptr->total_length += handle_zero(ptr->lenght, ptr);
	}
	if (!(ptr->precesion && !num))
		ptr->total_length += ft_put_nbr_base(base,
				(unsigned int) num, ft_strlen(base), ptr);
}

int	handle_x(long long num, t_format *ptr, char *base, char *prefix)
{
	calculat_width_lenght(ptr, &num);
	if (ptr->minus)
		handle_left(num, ptr, base, prefix);
	else
		handle_right(num, ptr, base, prefix);
	return (ptr->total_length);
}
