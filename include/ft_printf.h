/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:19:04 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/01 14:48:38 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

#include "parser.h"
#include "libft.h"

int		handle_d(long num, format *ptr);

int		ft_putstr(char *str, size_t	len);
int 	ft_putchar(int c);
void	handle_hash(void);
void	handle_minus(void);
void	handle_plus(void);
void	handle_zero(size_t	len);
void	handle_space(size_t	len);
int	calc_num_base(int base, long num);
void	ft_put_nbr_base(char *base, long num,size_t len);

#endif