/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:11:23 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/25 11:03:58 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

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

void	map_fail(t_root *root, int i)
{
	if (i == 1)
		ft_putstr("Error\nCheck your Map Walls.\n");
	else if (i == 2)
		ft_putstr("Error\nMissing or Unreachable Collectables\n");
	else if (i == 3)
		ft_putstr("Error\nMissing or Unreachable Exit\n");
	else if (i == 4)
		ft_putstr("Error\nMissing Player\n");
	else if (i == 5)
		ft_putstr("Error\nOnly one Player allowed!\n");
	else if (i == 6)
		ft_putstr("Error\nOnly one Exit allowed!\n");
	else if (i == 7)
		ft_putstr("Error\nInvalid character!\n");
	else if (i == 8)
	{
		ft_putstr("Error\nMap not found!\n");
		exit(0);
	}
	close_window(root);
}

void	map_counter(t_root *root)
{
	root->i = 0;
	root->j = 0;
	root->c_exit = 0;
	root->c_player = 0;
	while (root->i < root->lines)
	{
		while (root->map_array[root->i][root->j] != '\n'
			&& root->map_array[root->i][root->j] != '\0')
		{
			if (root->map_array[root->i][root->j] == root->tile.a_exit)
				root->c_exit++;
			else if (root->map_array[root->i][root->j] == root->tile.a_player)
				root->c_player++;
			root->j++;
		}
		root->j = 0;
		root->i++;
	}
	if (root->c_exit > 1)
		map_fail(root, 6);
	else if (root->c_player > 1)
		map_fail(root, 5);
	root->c_exit = 0;
	root->c_player = 0;
}

void	map_check(t_root *root, t_point ffsize, t_point ffbegin)
{
	root->i = 0;
	root->j = 0;
	collect_count(root);
	while (root->i < root->lines)
	{
		if (root->map_array[root->i][root->j] != root->tile.a_wall
			|| root->map_array[root->i][root->columns - 1] != root->tile.a_wall)
			map_fail(root, 1);
		else
			root->i++;
	}
	root->i = 0;
	root->j = 0;
	while (root->j < root->columns)
	{
		if (root->map_array[root->i][root->j] != root->tile.a_wall
			|| root->map_array[root->lines - 1][root->j++] != root->tile.a_wall)
			map_fail(root, 1);
		else
			root->j++;
	}
	flood_fill(ffsize, ffbegin, root);
	map_validate(root);
	map_counter(root);
}
