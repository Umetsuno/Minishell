/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oghma <fabien@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:02:02 by faherrau          #+#    #+#             */
/*   Updated: 2021/09/03 14:09:33 by oghma            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "MiniShell.h"

int	ft_token(t_data *data, char c, char *token);
int parsing_split(t_data *data, char *limit);

#endif
