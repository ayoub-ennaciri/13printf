/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:02:47 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/19 22:41:55 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_printf.h"
#include "../include/printing.h"
#include "../include/calculations.h"
#include <stdio.h>

int		handle_s(char *s, format *ptr)
{
	calculat_width_lenght(ptr, (void *)s);
	if (ptr->minus)
	{
			ft_putstr(s, ptr->lenght);
		handle_space(ptr->width);
	}
	else
	{
		handle_space(ptr->width);
			ft_putstr(s, ptr->lenght);
	}
	return (ptr->width + ptr->lenght);
}



int	manage_form_specifiers(char **s, va_list *args)
{
	format	*ptr;
	int total_len;

	total_len = 0;
	ptr = parse(s);
	if (!ptr->valid)
		return (0);
	else if (ptr->type == 's')
		total_len = handle_s(va_arg(*args, char *), ptr);
	//else if (ptr->type == 'c')
	//	total_len = handle_c(va_arg(*args, int), ptr);
	else if (ptr->type == 'd' || ptr->type == 'i')
		total_len = handle_d(va_arg(*args, int), ptr);
	else if (ptr->type == 'u')
		total_len = handle_d(va_arg(*args, unsigned int), ptr);
	else if (ptr->type == 'x')
		total_len = handle_x(va_arg(*args, int), ptr, BASE_16_x, x);
	else if (ptr->type == 'X')
		total_len = handle_x(va_arg(*args, int), ptr, BASE_16_X, X);
	else if (ptr->type == 'p')
		total_len = handle_x(va_arg(*args, unsigned long), ptr, BASE_16_x, x);
	else if (ptr->type == '%')
	//	ft_putchar('%');
	return (1);
}
