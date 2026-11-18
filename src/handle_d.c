/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:33:58 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/18 16:01:52 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

//static void	on_off(format *ptr, long num)
//{
//	if (ptr->minus && !ptr->width_act)
//		ptr->minus = FALSE;
//	if (ptr->space && (ptr->plus || num < 0))
//		ptr->space = FALSE;
//	if (ptr->zero && (ptr->minus || !ptr->width_act || ptr->precesion))
//		ptr->zero = FALSE;
//	if (ptr->plus && num < 0)
//		ptr->plus = FALSE;
//	if (num < 0)
//		ptr->lenght += 1;
//}

//static void	left_aligned(format *ptr, long num, int tmp, int len)
//{
//	int s;

//	s = 0;
//	if (ptr->space || ptr->plus)
//		s = -1;
//	if (ptr->space && !ptr->plus)
//		ft_putchar(' ');
//	if (ptr->plus)
//		ft_putchar('+');
//	if (num < 0)
//		ft_putchar('-');
//	handle_zero(tmp - len);
//	if (!num && ptr->lenght_act && !ptr->lenght);
//	else
//		ft_put_nbr_base(BASE_10, num, ft_strlen(BASE_10));
//	handle_space(ptr->width - tmp + s);
//}

//static void right_aligned(format *ptr, long num, int tmp, int len)
//{
//	int s;

//	s = 0;
//	if (ptr->space || ptr->plus)
//		s = -1;
//	if (ptr->zero)
//	{
//		if (ptr->plus)
//			ft_putchar('+');
//		if (num < 0)
//			ft_putchar('-');
//		handle_zero(ptr->width - tmp + s);
//	}
//	else
//	{
//		handle_space(ptr->width - tmp + s);
//		if (ptr->plus)
//			ft_putchar('+');
//		if (num < 0)
//			ft_putchar('-');
//	}
//	if (ptr->space && !ptr->plus)
//		ft_putchar(' ');
//	handle_zero(tmp - len);
//	if (!num && ptr->lenght_act && !ptr->lenght)
//		return;
//	ft_put_nbr_base(BASE_10, num, ft_strlen(BASE_10));
//}

//int	handle_d(long num, format *ptr)
//{
//	int	len;
//	int	tmp;

//	on_off(ptr, num);
//	len = calc_num_base(10, num);
//	if (len < ptr->lenght)
//		tmp = ptr->lenght;
//	else
//		tmp = len;
//	if (ptr->minus)
//		left_aligned(ptr, num, tmp, len);
//	else
//		right_aligned(ptr, num, tmp, len);
//	if (ptr->width > tmp)
//		return (ptr->width);
//	else
//		return (tmp);
//}

int	handle_d(long num, format *ptr)
{
	calculat_width_lenght(ptr, &num);
	if (ptr->minus)
	{
		if (ptr->space)
			ft_putchar(' ');
		if (ptr->precesion)
			handle_zero(ptr->lenght);
		else if (ptr->zero)
			handle_zero(ptr->width);
		ft_put_nbr_base(10, num, ft_strlen(BASE_10));
	}
	else
	{
		if (ptr->space)
			ft_putchar(' ');
		if (ptr->precesion)
			handle_zero(ptr->lenght);
		else if (ptr->zero)
			handle_zero(ptr->width);
		ft_put_nbr_base(10, num, ft_strlen(BASE_10));
	}
		return (0);
}