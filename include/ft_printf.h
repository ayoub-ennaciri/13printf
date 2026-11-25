/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:19:04 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:08:19 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "parser.h"
# include <stdarg.h>

# define BASE_10 "0123456789"
# define BASE_16_L_X "0123456789abcdef"
# define BASE_16_U_X "0123456789ABCDEF"
# define U_X "0X"
# define L_X "0x"

int	ft_printf(const char *s, ...);
int	handle_d(long num, t_format *ptr);
int	handle_x(long long num, t_format *ptr, char *base, char *prefix);
int	handle_c(char c, t_format *ptr);
int	handle_p(long num, t_format *ptr, char *base, char *prefix);

int	manage_form_specifiers(char **s, va_list *args);

#endif