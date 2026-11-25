/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:13:44 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:10:44 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/printing.h"

int	handle_c(char c, t_format *ptr)
{
	if (ptr->minus)
	{
		ptr->total_length += ft_putchar(c, ptr);
		ptr->total_length += handle_space(ptr->width - 1, ptr);
	}
	else
	{
		ptr->total_length += handle_space(ptr->width - 1, ptr);
		ptr->total_length += ft_putchar(c, ptr);
	}
	return (ptr->total_length);
}
