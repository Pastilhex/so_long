/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:08:20 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/21 22:20:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	close_window(t_root *root)
{
	int	size;

	size = root->lines - 1;
	if (root->mlx)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (root->mlx_win)
		mlx_destroy_display(root->mlx);
	if (root->map_array)
	{
		while (size >= 0)
		{
			free(root->map_array[size]);
			free(root->map_check[size--]);
		}
		free(root->map_array);
		free(root->map_check);
	}
	free(root->mlx);
	exit(0);
	return (0);
}

int	sqr_len(char *word)
{
	int	i;

	i = 0;
	if (!word)
		return (0);
	while (word[i] && word[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	check_square(t_root *root)
{
	root->i = root->lines - 1;
	root->sqr_size = 0;
	root->sqr_flag = 0;
	root->fd = acess_file(root);
	root->str = get_next_line(root->fd);
	root->sqr_size = sqr_len(root->str);
	free(root->str);
	if (root->sqr_size == 0)
		root->sqr_flag = 1;
	else
	{
		while (root->i > 0)
		{
			root->str = get_next_line(root->fd);
			if ((sqr_len(root->str) != root->sqr_size && root->str) || sqr_len(root->str) == 0)
				root->sqr_flag = 1;
			free(root->str);
			root->i--;
		}
	}
	if (root->sqr_flag == 1)
	{	
		ft_putstr("Error\nMap is not square!\n");
		free(root->str);
		close_window(root);
	}
}
