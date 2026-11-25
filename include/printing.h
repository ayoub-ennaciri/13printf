/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:02:18 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:07:50 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H

# include "libft.h"

int	handle_zero(int len, t_format *ptr);
int	handle_space(int len, t_format *ptr);
int	ft_putstr(char *str, t_format *ptr);
int	ft_put_nbr_base(char *base, long num, long base_len, t_format *ptr);
int	p_ft_put_nbr_base(char *base, unsigned long num, t_format *ptr);
int	ft_putchar(int c, t_format *ptr);

#endif