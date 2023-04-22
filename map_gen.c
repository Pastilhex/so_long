/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:25:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/21 22:12:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	map_count(t_root *root)
{
	root->c_collectable = 0;
	root->c_player = 0;
	root->c_exit = 0;
	root->c_other = 0;
	root->lines = 0;
	root->columns = 0;
	root->tile.moves = 0;
	root->i = 1;
	root->fd = acess_file(root);
	while (root->i)
	{
		root->str = get_next_line(root->fd);
		if (root->str)
			root->columns = len(root->str);
		else
			root->i = 0;
		root->lines++;
		free (root->str);
	}
	root->lines -= 1;
	close(root->fd);
}

void	build_array(t_root *root)
{
	root->i = 0;
	root->j = -1;
	root->size = root->lines;
	root->map_array = (char **)malloc(root->lines * sizeof(char *));
	if (root->map_array)
	{
		root->fd = acess_file(root);
		while (root->size > 0)
		{
			root->str = get_next_line(root->fd);
			root->map_array[root->i] = (char *)malloc
				(len(root->str) * sizeof(char) + 1);
			if (root->map_array[root->i])
			{
				while (++root->j < len(root->str))
					root->map_array[root->i][root->j] = root->str[root->j];
				root->map_array[root->i++][root->j] = '\0';
				root->j = -1;
				root->size--;
			}
			free(root->str);
		}
	}
	close(root->fd);
}

void	build_copy(t_root *root)
{
	root->i = 0;
	root->j = -1;
	root->size = root->lines;
	root->map_check = (char **)malloc(root->lines * sizeof(char *));
	if (root->map_check)
	{
		root->fd = acess_file(root);
		while (root->size > 0)
		{
			root->str = get_next_line(root->fd);
			root->map_check[root->i] = (char *)malloc
				(len(root->str) * sizeof(char) + 1);
			if (root->map_check[root->i])
			{
				while (++root->j < len(root->str))
					root->map_check[root->i][root->j] = root->str[root->j];
				root->map_check[root->i++][root->j] = '\0';
				root->j = -1;
				root->size--;
			}
			free(root->str);
		}
	}
	close(root->fd);
	search_player(root);
}

void	search_player(t_root *root)
{
	root->i = 0;
	root->j = 0;
	while (root->i < root->lines)
	{
		while (root->map_array[root->i][root->j] != '\n'
			&& root->map_array[root->i][root->j] != '\0')
		{
			if (root->map_array[root->i][root->j] == root->tile.a_player)
			{
				root->pl_x = root->j;
				root->pl_y = root->i;
			}
			root->j++;
		}
		root->j = 0;
		root->i++;
	}
	root->tile.exit_flag = 0;
}

char	*gen_walls(t_root *root)
{
	if (root->i == 0 && root->j == 0)
		return (root->tile.wall_top_left);
	else if (root->i == 0 && root->j > 0 && root->j < root->columns - 1)
		return (root->tile.wall_top);
	else if (root->i == 0 && root->j == root->columns - 1)
		return (root->tile.wall_top_right);
	else if (root->i == root->lines - 1 && root->j == 0)
		return (root->tile.wall_bottom_left);
	else if (root->i == root->lines - 1
		&& root->j > 0 && root->j < root->columns - 1)
		return (root->tile.wall_bottom);
	else if (root->i == root->lines - 1 && root->j == root->columns - 1)
		return (root->tile.wall_bottom_right);
	else if (root->j == 0)
		return (root->tile.wall_left);
	else if (root->j == root->columns - 1)
		return (root->tile.wall_right);
	else
		return (root->tile.wall);
}
