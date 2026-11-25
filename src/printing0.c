/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:44:55 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:11:59 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putchar(int c, t_format *ptr)
{
	if (ptr->error)
		return (0);
	if (write(1, (unsigned char *)&c, 1) == -1)
	{
		ptr->error = 1;
		return (0);
	}
	return (1);
}

int	handle_zero(int len, t_format *ptr)
{
	int	i;

	if (ptr->error)
		return (0);
	i = 0;
	while (i < len)
	{
		if (ft_putchar('0', ptr) == -1)
			return (0);
		i++;
	}
	return (i);
}

int	handle_space(int len, t_format *ptr)
{
	int	i;

	if (ptr->error)
		return (0);
	i = 0;
	while (i < len)
	{
		if (ft_putchar(' ', ptr) == -1)
			return (0);
		i++;
	}
	return (i);
}

int	ft_putstr(char *str, t_format *ptr)
{
	int	i;

	if (ptr->error)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ptr->precesion && i >= ptr->lenght)
			break ;
		if (ft_putchar(str[i], ptr) == -1)
			return (0);
		i++;
	}
	return (i);
}

int	ft_put_nbr_base(char *base, long num, long base_len, t_format *ptr)
{
	int	printed_len;

	printed_len = 0;
	if (ptr->error)
		return (0);
	if (base_len == 10 && num < 0)
		num = -num;
	if (base_len == 16 && num < 0)
		printed_len += ft_put_nbr_base(base,
				((unsigned long)num) / base_len, base_len, ptr);
	else if (num >= base_len)
		printed_len += ft_put_nbr_base(base, num / base_len, base_len, ptr);
	if (write(1, &base[num % base_len], 1) == -1)
	{
		ptr->error = 1;
		return (0);
	}
	return (++printed_len);
}
