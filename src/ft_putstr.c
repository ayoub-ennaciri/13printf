/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 21:41:12 by ayennaci          #+#    #+#             */
/*   Updated: 2026/10/31 16:24:22 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/parser.h"
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
