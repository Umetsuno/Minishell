/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:35:23 by lduplain          #+#    #+#             */
/*   Updated: 2021/05/21 17:41:57 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "MiniShell.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/*
**			GET_NEXT_LINE.C CONTENT
*/

int		get_next_line(int fd, char **line);

/*
**			GET_NEXT_LINE_UTILS.C CONTENT
*/

size_t	fh_strlen(const char *s);
size_t	fh_strcpy(char *dst, const char *src);
char	*fh_strjoin(char const *s1, char const *s2);
int		contains(char *str, char c);

#endif
