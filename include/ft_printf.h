/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:19:04 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/24 17:24:12 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

#include <stdarg.h>
#include "parser.h"

#define BASE_10 "0123456789" 
#define BASE_16_x "0123456789abcdef" 
#define BASE_16_X "0123456789ABCDEF" 
#define X "0X"
#define x "0x"

int 	ft_printf(const char *s, ...);

int		handle_d(long num, format *ptr);
int		handle_x(long long num, format *ptr, char *base, char *prefix);
int		handle_c(char c, format *ptr);

int		manage_form_specifiers(char **s, va_list *args);

#endif