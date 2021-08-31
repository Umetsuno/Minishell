/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:04:51 by faherrau          #+#    #+#             */
/*   Updated: 2021/08/31 14:17:31 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "MiniShell.h"

/*
**	--- utils ---
**	function_env.c
*/
int		size_env(char **env);
char	**copy_env(char **env);
char	*my_getenv(t_data *data, char *str);
void	copy_env_add_one(t_data *data, char *new_elem);
void	copy_env_del_one(t_data *data, int index_elem_to_del);

#endif
