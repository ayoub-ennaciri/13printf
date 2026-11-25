/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:02:47 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:28:19 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"
#include "../include/calculations.h"

int	handle_s(char *s, t_format *ptr)
{
	if (!s)
	{
		ptr->total_length += ft_putstr("(null)", ptr);
		return (ptr->total_length);
	}
	calculat_width_lenght(ptr, (void *)s);
	if (ptr->minus)
	{
		ptr->total_length += ft_putstr(s, ptr);
		ptr->total_length += handle_space(ptr->width, ptr);
	}
	else
	{
		ptr->total_length += handle_space(ptr->width, ptr);
		ptr->total_length += ft_putstr(s, ptr);
	}
	return (ptr->total_length);
}

int	idk(t_format *ptr, int total_len)
{
	if (ptr->error)
	{
		free(ptr);
		return (-1);
	}
	free(ptr);
	return (total_len);
}

int	manage_form_specifiers(char **s, va_list *args)
{
	t_format	*ptr;
	int			total_len;

	total_len = 0;
	ptr = parse(s);
	if (!ptr->valid)
		return (0);
	else if (ptr->type == 's')
		total_len = handle_s(va_arg(*args, char *), ptr);
	else if (ptr->type == 'c')
		total_len = handle_c(va_arg(*args, int), ptr);
	else if (ptr->type == 'd' || ptr->type == 'i')
		total_len = handle_d(va_arg(*args, int), ptr);
	else if (ptr->type == 'u')
		total_len = handle_d(va_arg(*args, unsigned int), ptr);
	else if (ptr->type == 'x')
		total_len = handle_x(va_arg(*args, int), ptr, BASE_16_L_X, L_X);
	else if (ptr->type == 'X')
		total_len = handle_x(va_arg(*args, int), ptr, BASE_16_U_X, U_X);
	else if (ptr->type == 'p')
		total_len = handle_p(va_arg(*args, unsigned long),
				ptr, BASE_16_L_X, L_X);
	else if (ptr->type == '%')
		total_len = ft_putchar('%', ptr);
	return (idk(ptr, total_len));
}
