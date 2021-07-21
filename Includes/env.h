/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <faherrau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:04:51 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/28 13:40:22 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "MiniShell.h"

int		size_env(char **env);
char	**copy_env(char **env);
char	*my_getenv(t_data *data, char *str);
void	copy_env_add_one(t_data *data, char *new_elem);
void	copy_env_del_one(t_data *data, int index_elem_to_del);


#endif
