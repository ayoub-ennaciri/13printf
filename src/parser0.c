/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:16:03 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/06 22:25:15 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/libft.h"

void	get_width(char **s, format	*ptr)
{
	size_t	num;

	num = 0;
	while (ft_isdigit(**s))
	{
		ptr->width_act = TRUE;
		if ((num * 10) + (**s - '0') <= 2147483647)
			num = (num * 10) + (**s - '0');
		(*s)++;
	}
	ptr->width = num;
}

void	get_precesion(char **s, format	*ptr)
{
	if(!ptr->precesion && **s == '.')
	{
		ptr->precesion = TRUE;
		(*s)++;
	}
	
}

void	get_form_specifier(char **s, format	*ptr)
{
	if (one_of(**s, "xXscduip%"))
	{
		if (**s == 'p')
			ptr->hash = 1;
		ptr->type = **s;
		ptr->valid = TRUE;
		(*s)++;
	}
}

format	*parse(char **s)
{
	format	*ptr;
	char *copy;

	copy = *s;
	(*s)++;
	ptr = ft_calloc(1, sizeof(format));
	if (!ptr)
		return (NULL);
	get_flags(s, ptr);
	get_width(s, ptr);
	get_precesion(s, ptr);
	get_lenght(s, ptr);
	get_form_specifier(s, ptr);
	if (!ptr->valid)
		*s = copy;
	return (ptr);
}

