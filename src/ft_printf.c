/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:14:09 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 13:49:24 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"

int	ft_printf(const char *s, ...)
{
	char		*copy;
	va_list		args;
	int			len;
	int			tmp_len;

	copy = (char *)s;
	len = 0;
	va_start(args, s);
	while (*copy)
	{
		if (*copy == '%')
		{
			tmp_len = manage_form_specifiers(&copy, &args);
			if (tmp_len == -1)
				return (va_end(args), -1);
			len += tmp_len;
		}
		else if (write(1, copy++, 1) == -1)
			return (va_end(args), -1);
		else
			len++;
	}
	va_end(args);
	return (len);
}
