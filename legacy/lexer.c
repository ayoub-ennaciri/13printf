/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:08:42 by ayennaci          #+#    #+#             */
/*   Updated: 2026/10/27 18:08:47 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokine.h"
#include "../include/libft.h"

int	tkn_in_range(char c)
{
	if ((c >= 32 && c <= 36) || (c >= 38 && c <= 47) ||(c >= 58 && c < 127))
		return (1);
	return (0);
}

int	tkn_is_peacial(char c, char *str)
{
	while (*str)
	{
		if(*str == c)
			return (1);
		str++;
	}
	return (0);
}

ls_token	*tkn_new(enm_type type, int start_indx, size_t lenght, int precedence)
{
	ls_token	*node;

	node = malloc(sizeof(ls_token));
	if(!node)
		return (NULL);
	node->type = type;
	node->start_indx = start_indx;
	node->lenght = lenght;
	node->precedence = precedence;
	node->next = NULL;
	return (node);
}

ls_token	**tkn_add_back(ls_token **tkn_head, ls_token *node)
{
	if(!tkn_head || ! node)
		return (NULL);
	if(!*tkn_head)
	{
		*tkn_head = node;
		return (tkn_head);
	}
	ls_token	*tmp = *tkn_head;
	while (tmp)
	{
		if(!(tmp)->next)
		{
			(tmp)->next = node;
			return (tkn_head);
		}
		tmp = (tmp)->next;
	}
	return (tkn_head);
}

void		tkn_clean(ls_token	*tkn_head)
{
	ls_token	*tmp;

	while (tkn_head)
	{
		tmp = tkn_head;
		tkn_head = tkn_head->next;
		free(tmp);
	}
}

ls_token	*tkn_get_alpha_str(char *str, size_t	start_indx, ls_token **tkn_head)
{
	size_t	len;
	ls_token	*node;
	
	len = 0;
	while (tkn_in_range(*str))
	{
		len++;
		str++;
	}
	node = tkn_new(STR, start_indx, len, PRECEDENCE_STR);
	if (!node)
	{
		tkn_clean(node);
		return (NULL);
	}
	if (!tkn_add_back(tkn_head, node))
	{
		tkn_clean(node);
		return (NULL);
	}
	return (node);
}

ls_token	*tkn_get_alpha_char(char *str, size_t	start_indx, ls_token **tkn_head)
{
	ls_token	*node;

	if(*str == '%')
		node = tkn_new(FSI, start_indx, 1, PRECEDENCE_FSI);
	else if(*str == 'c')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == 's')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == 'p')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == 'd')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == 'i')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == 'u')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == 'x')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == 'X')
		node = tkn_new(FSP, start_indx, 1, PRECEDENCE_FSP);
	else if(*str == '#')
		node = tkn_new(HSH, start_indx, 1, PRECEDENCE_HSH);
	else if(*str == '.')
		node = tkn_new(PRC, start_indx, 1, PRECEDENCE_PRC);
	else if(*str == ' ')
		node = tkn_new(SPC, start_indx, 1, PRECEDENCE_SPC);
	else if(*str == '0')
		node = tkn_new(ZRO, start_indx, 1, PRECEDENCE_ZRO);
	else if(*str == '+')
		node = tkn_new(PLS, start_indx, 1, PRECEDENCE_PLS);
	else if(*str == '-')
		node = tkn_new(MIN, start_indx, 1, PRECEDENCE_MIN);
	if (!node)
	{
		tkn_clean(node);
		return (NULL);
	}
	if (!tkn_add_back(tkn_head, node))
	{
		tkn_clean(node);
		return (NULL);
	}
	return (node);
}

ls_token	*tkn_get_num_str(char *str, size_t	start_indx, ls_token **tkn_head)
{
	size_t	len;
	ls_token	*node;
	
	len = 0;
	if (*str == '0')
		return (tkn_get_alpha_char(str, start_indx, tkn_head));
	while (ft_isdigit(*str))
	{
		len++;
		str++;
	}
	node = tkn_new(NUM, start_indx, len, PRECEDENCE_NUM);
	if (!node)
	{
		tkn_clean(node);
		return (NULL);
	}
	if (!tkn_add_back(tkn_head, node))
	{
		tkn_clean(node);
		return (NULL);
	}
	return (node);
}

ls_token	*lex(char *str)
{
	size_t		i;
	int			char_mode;
	ls_token	*tkn_head;
	ls_token	*node;

	i = 0;
	tkn_head = NULL;
	node = NULL;
	char_mode = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			node = tkn_get_num_str(&(str[i]), i, &tkn_head);
			if (!node)
				return (NULL);
			i += node->lenght;
		}
		else if(!char_mode)
		{
			if (tkn_is_peacial(str[i], "%") )
					char_mode = !char_mode;
			else if (tkn_in_range(str[i]))
			{
				node = tkn_get_alpha_str(&(str[i]), i, &tkn_head);
				if (!node)
					return (NULL);
				i += node->lenght;
			}
		}
		else if(char_mode)
		{
			if (!tkn_is_peacial(str[i], "%.+- #0dixXscpu") && !ft_isdigit(str[i]))
				char_mode = !char_mode;
			else
				{
					if(tkn_is_peacial(str[i], "dixXscpu"))
						char_mode = !char_mode;
					node = tkn_get_alpha_char(&(str[i]), i, &tkn_head);
					if (!node)
						return (NULL);
					i += node->lenght;
				}
		}
	}
	return (tkn_head);
}