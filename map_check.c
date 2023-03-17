/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:11:23 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/17 23:05:46 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	collect_count(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	root->collected_sum = 0;
	while (i < root->lines)
	{
		while (root->map_array[i][j] != '\n' && root->map_array[i][j] != '\0')
		{
			if (root->map_array[i][j] == root->tile.a_collectable)
				root->collected_sum++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	search_exit(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < root->lines)
	{
		while (root->map_array[i][j] != '\n' && root->map_array[i][j] != '\0')
		{
			if (root->map_array[i][j] == root->tile.a_exit)
			{
				root->exit_x = j;
				root->exit_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	root->texture_path = root->tile.exit_open;
	gen_img(root->exit_x, root->exit_y, root);
}

void	verify_map(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < root->lines)
		if (root->map_array[i][j] != root->tile.a_wall && root->map_array[i][root->columns-1] != root->tile.a_wall)
		{
			ft_putstr("Map Integrity Fail\n");
			i++;
		}
		else
			i++;
		
	i = 0;
	j = 0;
	while (j < root->columns)
		if (root->map_array[i][j] != root->tile.a_wall && root->map_array[root->lines-1][j] != root->tile.a_wall)
		{
			ft_putstr("\nIntegrity Y Map Fail\n");
			close_window(root);
			j++;
		}
		else
			j++;
}