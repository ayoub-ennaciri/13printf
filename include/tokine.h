/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:44:27 by ayennaci          #+#    #+#             */
/*   Updated: 2026/10/27 18:04:11 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKINE_H
#define	TOKINE_H

#include "libft.h"

#define PRECEDENCE_FSI 50
#define PRECEDENCE_PRC 40
#define PRECEDENCE_NUM 30
#define PRECEDENCE_MIN 30
#define PRECEDENCE_PLS 30
#define PRECEDENCE_SPC 30
#define PRECEDENCE_ZRO 30
#define PRECEDENCE_HSH 30
#define PRECEDENCE_FSP 20 
#define PRECEDENCE_STR 10

typedef enum enm_type
{
	FSI,
	NUM,
	MIN,
	PLS,
	SPC,
	ZRO,
	HSH,
	PRC,
	FSP,	//format specifier
	STR,
} enm_type;

typedef struct ls_token
{
	enm_type 			type;
	size_t 			start_indx;
	size_t 			lenght;
	int				precedence;
	struct ls_token	*next;
} ls_token; 

ls_token	*tkn_new(enm_type type, int start_indx, size_t lenght, int precedence);
ls_token	**tkn_add_back(ls_token **tkn_head, ls_token *node);
void		tkn_clean(ls_token	*tkn_head);
ls_token	*tkn_get_alpha_str(char *str, size_t	start_indx, ls_token **tkn_head);
ls_token	*tkn_get_alpha_char(char *str, size_t	start_indx, ls_token **tkn_head);
ls_token	*tkn_get_num_str(char *str, size_t	start_indx, ls_token **tkn_head);
int			tkn_is_peacial(char c, char *str);
ls_token	*lex(char *str);

#endif