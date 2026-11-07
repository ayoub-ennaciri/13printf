/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:02:47 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/06 23:12:28 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_printf.h"
#include <stdio.h>

int		handle_s(char *s, format *ptr)
{
	int	len;

	len = ft_strlen(s);
	if (ptr->lenght_act && len > ptr->lenght)
		len = ptr->lenght;
	if (ptr->width > len)
		ptr->width = ptr->width - len;
	else if (ptr->width)
		ptr->width = 0;
	if (ptr->minus)
	{
		if (len)
			ft_putstr(s, len);
		handle_space(ptr->width);
	}
	else
	{
		handle_space(ptr->width);
		if (len)
			ft_putstr(s, len);
	}
	return (ptr->width + len);
}



int	manage_form_specifiers(char **s, va_list *args)
{
	format	*ptr;

	ptr = parse(s);
	if (!ptr->valid)
		return (0);
	else if (ptr->type == 's')
		handle_s(va_arg(*args, char *), ptr);
	else if (ptr->type == 'c')
		handle_c(va_arg(*args, int), ptr);
	else if (ptr->type == 'd' || ptr->type == 'i')
		handle_d(va_arg(*args, int), ptr);
	else if (ptr->type == 'u')
		handle_d(va_arg(*args, unsigned int), ptr);
	else if (ptr->type == 'x' || ptr->type == 'p')
		handle_x(va_arg(*args, int), ptr, BASE_16_x);
	else if (ptr->type == 'X')
		handle_x(va_arg(*args, int), ptr, BASE_16_X);
	else if (ptr->type == '%')
		ft_putchar('%');
	return (1);
}
