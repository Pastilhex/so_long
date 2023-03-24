/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:11:23 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/24 10:02:25 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	collect_count(t_root *root)
{
	root->i = 0;
	root->j = 0;
	root->collected_sum = 0;
	while (root->i < root->lines)
	{
		while (root->map_array[root->i][root->j] != '\n' && root->map_array[root->i][root->j] != '\0')
		{
			if (root->map_array[root->i][root->j] == root->tile.a_collectable)
				root->collected_sum++;
			root->j++;
		}
		root->j = 0;
		root->i++;
	}
}

void	search_exit(t_root *root)
{
	root->i = 0;
	root->j = 0;
	while (root->i < root->lines)
	{
		while (root->map_array[root->i][root->j] != '\n' && root->map_array[root->i][root->j] != '\0')
		{
			if (root->map_array[root->i][root->j] == root->tile.a_exit)
			{
				root->exit_x = root->j;
				root->exit_y = root->i;
			}
			root->j++;
		}
		root->j = 0;
		root->i++;
	}
	root->texture_path = root->tile.exit_open;
	gen_img(root->exit_x, root->exit_y, root);
}

void	map_fail(t_root *root, int i)
{
	if (i == 1)
		ft_putstr("Map Integrity Fail! Check your Map Walls.\n");
	else if (i == 2)
		ft_putstr("Map Integrity Fail! Missing or Unreachable Collectables\n");
	else if (i == 3)
		ft_putstr("Map Integrity Fail! Missing or Unreachable Exit\n");
	else if (i == 4)
		ft_putstr("Map Integrity Fail! Missing Player\n");
	else if (i == 5)
		ft_putstr("Map Integrity Fail! Only one Player allowed!\n");
	else if (i == 6)
		ft_putstr("Map Integrity Fail! Only one Exit allowed!\n");
	else if (i == 7)
		ft_putstr("Map Integrity Fail! Invalid character!\n");
	else if (i == 8)
	{
		ft_putstr("Map not found!\n");
		exit(0);
	}
	close_window(root);
}

void	map_validate(t_root *root)
{
	if (root->c_collectable < 1 || root->c_collectable < root->collected_sum)
		map_fail(root, 2);
	if (root->c_exit < 1)
		map_fail(root, 3);
	if (root->c_exit > 1)
		map_fail(root, 6);
	if (root->c_player < 1)
		map_fail(root, 4);
	if (root->c_player > 1)
		map_fail(root, 5);
	if (root->c_other > 0)
		map_fail(root, 7);
}

void	map_check(t_root *root)
{
	root->c_collectable = 0;
	root->c_player = 0;
	root->c_exit = 0;
	root->c_other = 0;
	collect_count(root);
	t_point	ffsize = {root->lines, root->columns};
	t_point	ffbegin = {root->pl_y, root->pl_x};
	root->i = 0;
	root->j = 0;
	while (root->i < root->lines)
		if (root->map_array[root->i][root->j] != root->tile.a_wall || root->map_array[root->i][root->columns-1] != root->tile.a_wall)
			map_fail(root, 1);
		else
			root->i++;
	root->i = 0;
	root->j = 0;
	while (root->j < root->columns)
		if (root->map_array[root->i][root->j] != root->tile.a_wall || root->map_array[root->lines-1][root->j++] != root->tile.a_wall)
			map_fail(root, 1);
		else
			root->j++;
	flood_fill(ffsize, ffbegin, root);
	map_validate(root);
}
