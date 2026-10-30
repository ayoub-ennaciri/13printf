/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 21:41:12 by ayennaci          #+#    #+#             */
/*   Updated: 2026/10/22 02:15:28 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/printf.h"

int	ft_putstr(char *str, int max)
{
	size_t	i;

	i = 0;
	while (str[i] && i < max)
	{
		ft_putchar(str[i]);
		i++;
	}	
}
