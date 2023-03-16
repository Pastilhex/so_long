/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:25:46 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/15 20:59:26 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	map_count_lines(t_root *root)
{
	root->size = 0;
	root->map_path = MAP_PATH;
	root->str = "start";
	root->fd = open(root->map_path, O_RDONLY);
	while (root->str != NULL)
	{
		root->str = get_next_line(root->fd);
		root->size++;
	}
	root->lines = root->size - 1;
	close(root->fd);
}

void	map_count_columns(t_root *root)
{
	root->size = 0;
	root->i = -1;
	root->map_path = MAP_PATH;
	root->fd = open(root->map_path, O_RDONLY);
	root->str = get_next_line(root->fd);
	while (root->str[++root->i] != '\0')
		root->size++;
	root->columns = root->size - 1;
	close(root->fd);
}

void	build_array(t_root *root)
{
	root->i = 0;
	root->j = -1;
	root->map_path = MAP_PATH;
	map_count_lines(root);
	root->map_array = (char **)malloc(root->lines * sizeof(char *));
	if (root->map_array)
	{
		root->fd = open(root->map_path, O_RDONLY);
		while (root->size > 0)
		{
			root->str = get_next_line(root->fd);
			root->map_array[root->i] = (char *)malloc
				(len(root->str) * sizeof(char) + 1);
			if (root->map_array[root->i])
			{
				while (++root->j < len(root->str))
					root->map_array[root->i][root->j] = root->str[root->j];
				root->map_array[root->i][root->j] = '\0';
				root->j = -1;
				root->i++;
				root->size--;
			}
		}
	}
	close(root->fd);
}

void	search_player(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (root->map_array[i][j] != '\0')
	{
		while (root->map_array[i][j] != '\n' && root->map_array[i][j] != '\0')
		{
			if (root->map_array[i][j] == root->tile.a_player)
			{
				root->pl_x = j;
				root->pl_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
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