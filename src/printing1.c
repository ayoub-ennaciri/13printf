/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:51:12 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:13:20 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	p_ft_put_nbr_base(char *base, unsigned long num, t_format *ptr)
{
	int	printed_len;

	printed_len = 0;
	if (num >= 16)
		printed_len += p_ft_put_nbr_base(base, num / 16, ptr);
	if (write(1, &base[num % 16], 1) == -1)
	{
		ptr->error = 1;
		return (0);
	}
	return (++printed_len);
}
