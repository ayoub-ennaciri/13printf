/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:16:29 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:08:00 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "parser.h"
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

typedef struct t_format
{
	char	type;
	int		hash;
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		precesion;
	int		valid;
	int		lenght_act;
	int		width_act;
	int		lenght;
	int		width;
	int		total_length;
	int		error;
}			t_format;

t_format	*parse(char **s);
int			one_of(char c, char *set);
void		get_flags(char **s, t_format *ptr);
void		get_lenght(char **s, t_format *ptr);

#endif