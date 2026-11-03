/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:30:51 by ayennaci          #+#    #+#             */
/*   Updated: 2026/10/31 15:45:19 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s++))
		count++;
	return (count);
}
