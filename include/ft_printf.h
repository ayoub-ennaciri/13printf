/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:19:04 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/06 22:05:39 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

#include <stdarg.h>
#include "parser.h"
#include "libft.h"

#define BASE_10 "0123456789" 
#define BASE_16_x "0123456789abcdef" 
#define BASE_16_X "0123456789ABCDEF" 

int ft_printf(const char *s, ...);


int		handle_d(long num, format *ptr);
int		handle_x(long num, format *ptr, char *base);
void	handle_c(char c, format *ptr);

int		manage_form_specifiers(char **s, va_list *args);
int		ft_putstr(char *str, size_t	len);
int 	ft_putchar(int c);
void	handle_zero(int	len);
void	handle_space(int len);
int		calc_num_base(int base, long num);
void	ft_put_nbr_base(char *base, long num,size_t base_len);

#endif