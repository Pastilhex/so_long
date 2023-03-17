/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:25:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/17 21:14:38 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include       <wchar.h>

int		len(char *word);
char	*join(char *s1, char *s2);
int		find(char *str, char c);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);

#endif