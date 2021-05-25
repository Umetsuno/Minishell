/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:16:42 by faherrau          #+#    #+#             */
/*   Updated: 2021/05/25 21:30:23 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_FUNCTIONS_H
# define BUILTINS_FUNCTIONS_H

# include "MiniShell.h"

void	ft_cd(t_data *data);
void	ft_echo(t_data *data);
void	ft_env(t_data *data);
void	ft_export(t_data *data);
void	ft_pwd(t_data *data);
void	ft_unset(t_data *data);
void	ft_exec_path(t_data *data);
void	ft_exec_builting_cmd(t_data *data);

#endif
