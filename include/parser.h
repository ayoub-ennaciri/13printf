/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:16:29 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/05 15:44:56 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCER_H
#define PARCER_H

#define	TRUE	1
#define	FALSE	0

typedef int bol;

typedef struct format
{
	char 	type;
	bol 	hash;
	bol 	plus;
	bol 	minus;
	bol 	zero;
	bol 	space;
	bol 	precesion;
	bol		valid;
	bol		lenght_act;
	bol		width_act;
	int		lenght;
	int		width;
}format;

format	*parse(char **s);
int one_of(char c, char	*set);
void	get_flags(char **s, format	*ptr);
void	get_lenght(char **s, format	*ptr);

#endif