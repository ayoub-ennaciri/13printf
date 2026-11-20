/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:33:58 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/20 13:09:45 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"
#include "../include/calculations.h"

static void handle_left(long num, format *ptr, char *base, char *prefix)
{
		if (num && ptr->hash)
			write(1, prefix, 2);
		if (ptr->precesion)
			handle_zero(ptr->lenght);
		if(!(ptr->precesion  && !num))
			ft_put_nbr_base(base,(unsigned int) num, ft_strlen(base));
		handle_space(ptr->width);
}
static void handle_right(long num, format *ptr, char *base, char *prefix)
{
	
	if (!(!ptr->precesion && ptr->zero))
		handle_space(ptr->width);
	else
	{
		if (num && ptr->hash)
		{
			ptr->hash = 0;
			write(1, prefix, 2);
		}
		handle_zero(ptr->width);
	}
	if (num && ptr->hash)
		write(1, prefix, 2);
	if (ptr->precesion)
	{
		handle_zero(ptr->lenght);
	}
	if(!(ptr->precesion && !num))
		ft_put_nbr_base(base,(unsigned int) num, ft_strlen(base));
}

int	handle_x(long num, format *ptr, char *base, char *prefix)
{
	calculat_width_lenght(ptr, &num);
	if (ptr->minus)
		handle_left(num, ptr, base, prefix);
	else
		handle_right(num, ptr, base, prefix);
	return (ptr->width + ptr->lenght);
}