/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:25:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/25 21:48:17 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[len(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	len(char *word)
{
	int	i;

	i = 0;
	if (!word)
		return (0);
	while (word[i])
		i++;
	return (i);
}

int	find(char *str, char c)
{
	int	i;
	int	flag;
	int	length;

	i = 0;
	flag = 0;
	length = len(str);
	while (i < length)
	{
		if (str[i] == c)
			flag = 1;
		i++;
	}
	return (flag);
}
