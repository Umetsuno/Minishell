/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:08 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/19 17:18:55 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct s_parsing
{
	char	*line;
	char	*command;
	char	*flag;
	char	*argument;
}				t_parsing;

typedef struct s_data
{
	int			i;
	char		*line;
	t_parsing	parsing;
}				t_data;

typedef enum e_code
{
	SUCCESS,
	FAIL,
}				t_code;

#endif
