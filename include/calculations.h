/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennaci <ayennaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:00:57 by ayennaci          #+#    #+#             */
/*   Updated: 2026/11/25 17:10:00 by ayennaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATIONS_H
# define CALCULATIONS_H

# include "libft.h"
# include "parser.h"

int	calculat_lenght(t_format *ptr, void *var);
int	calculat_width_lenght(t_format *ptr, void *var);

#endif