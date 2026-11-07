/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:33:58 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/07 10:24:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	on_off(format *ptr, long num)
{
	if (ptr->minus && !ptr->width_act)
		ptr->minus = FALSE;
	if (ptr->space && (ptr->plus || num < 0))
		ptr->space = FALSE;
	if (ptr->zero && (ptr->minus || !ptr->width_act || ptr->precesion))
		ptr->zero = FALSE;
	if (ptr->plus && num < 0)
		ptr->plus = FALSE;	
}

static int	left_aligned(format *ptr, long num, char *base)
{
	int	len;
	int	tmp;

	len = calc_num_base(16, num);
	if (len < ptr->lenght)
		tmp = ptr->lenght;
	else
		tmp = len;
	if (ptr->hash)
		ft_putstr("0x", 0);
	handle_zero(tmp - len - (2 * ptr->hash));
	ft_put_nbr_base(base, num, ft_strlen(base));
	handle_space(ptr->width - tmp);
	return (tmp);
}

static int right_aligned(format *ptr, long num, char *base)
{
	int	len;
	int	tmp;

	len = calc_num_base(16, num);
	if (len < ptr->lenght)
		tmp = ptr->lenght;
	else
		tmp = len;
	handle_space(ptr->width - tmp  - (2 * ptr->hash));
	if (ptr->hash)
		ft_putstr("0x", 0);
	handle_zero(tmp - len);
	ft_put_nbr_base(base, num, ft_strlen(base));
	return (tmp);
}

int	handle_x(long num, format *ptr, char *base)
{
	int	tmp;

	on_off(ptr, num);
	if (ptr->minus)
		tmp = left_aligned(ptr, num, base);
	else
		tmp = right_aligned(ptr, num, base);
	if (ptr->width > tmp)
		return (ptr->width);
	else
		return (tmp);
}
