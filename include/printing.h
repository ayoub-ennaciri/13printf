/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:02:18 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/24 18:40:43 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CALCULATIONS_H
# define	CALCULATIONS_H

#include "libft.h"

int	handle_zero(int	len, format *ptr);
int	handle_space(int len, format *ptr);
int		ft_putstr(char *str, format *ptr);
int	ft_put_nbr_base(int printed_len, char *base,  long num,long base_len, format *ptr);
int	p_ft_put_nbr_base(int printed_len, char *base, unsigned long num,long base_len, format *ptr);
int ft_putchar(int c, format *ptr);

#endif