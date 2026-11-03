/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:02:47 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/03 20:20:00 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_printf.h"

int		handle_s(char *s, format *ptr)
{
	int	len;

	len = ft_strlen(s);
	if (ptr->lenght_act && len > ptr->lenght)
		len = ptr->lenght;
	if (ptr->width > len)
		ptr->width = ptr->width - len;
	else
		ptr->width = 0;
	if (ptr->minus)
	{
		ft_putstr(s, len);
		handle_space(ptr->width);
	}
	else
	{
		handle_space(ptr->width);
		ft_putstr(s, len);
	}
	return (ptr->width + len);
}



void	manage_form_specifiers(char **s)
{
	format	*ptr;

	ptr = parse(s);
	if (ptr->type == 's')
		handle_s("walid nigga", ptr);
	else if (ptr->type == 'd')
		handle_d(2147483647, ptr);
		
}

void	switcher(char *s)
{
	while (*s)
	{
		if (*s == '%')
			manage_form_specifiers(&s);
		s++;
	}
	
}

int main()
{
	char *s = " d";
	manage_form_specifiers(&s);
	//"          walid"
	return 0;
}

//-2147483647         
//000000000000000000002147483647
//0000000000000002147483647
//0000000000000002147483647