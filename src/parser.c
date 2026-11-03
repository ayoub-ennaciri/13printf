/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:16:03 by ayennaci          #+#    #+#             */
/*   Updated: 2026/10/31 16:19:48 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/libft.h"


int one_of(char c, char	*set)
{
	while (*set)
	{
		if(c == *set)
			return (1);
		set++;
	}
	return (0);
}

void	get_flags(char **s, format	*ptr)
{
	while (one_of(**s, "+-0 #"))
	{
		if (**s == ' ' && !ptr->space)
			ptr->space = TRUE;
		else if (**s == '-' && !ptr->minus)
			ptr->minus = TRUE;
		else if (**s == '+' && !ptr->plus)
			ptr->plus = TRUE;
		else if (**s == '0' && !ptr->zero)
			ptr->zero = TRUE;
		else if (**s == '#' && !ptr->hash)
			ptr->hash = TRUE;
		else
			ptr->valid = FALSE;
		(*s)++;
	}
}

void	get_lenght(char **s, format	*ptr)
{
	size_t	num;

	num = 0;
	while (ft_isdigit(**s))
	{
		ptr->lenght_act = TRUE;
		if ((num * 10) + (**s - '0') <= 2147483647)
			num = (num * 10) + (**s - '0');
		(*s)++;
	}
	ptr->lenght = num ;
}

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
	char	*set = "xXscduip%";
	while (*set)
	{
		if (**s == *set)
		{
			ptr->type = **s;
			break;
		}
		set++;
	}
	
}

format	*parse(char **s)
{
	format	*ptr;

	ptr = malloc(sizeof(format));
	if (!ptr)
		return (NULL);
	get_flags(s, ptr);
	get_width(s, ptr);
	get_precesion(s, ptr);
	get_lenght(s, ptr);
	get_form_specifier(s, ptr);
	return (ptr);
}

