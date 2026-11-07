/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 21:41:12 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/06 21:59:34 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *str, size_t	len)
{
	size_t	i;
	bol		mode;

	if(!len)
		mode = FALSE;
	else
		mode = TRUE;
	i = 0;
	while (str[i])
	{
		if (mode && i >= len)
			break;
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
