/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:11:23 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/15 21:27:06 by pastilhex        ###   ########.fr       */
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
	while (root->map_array[i][j] != '\0')
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
	while (root->map_array[i][j] != '\0')
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

// void	verify_map(t_root *root)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (root->map_array[i][j] != '\0')
// 	{
// 		while (root->map_array[i][j] != '\n' && root->map_array[i][j] != '\0')
// 		{
// 			if (root->map_array[i][j] == root->tile.a_wall && )
// 			{
				
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	root->texture_path = root->tile.exit_open;
// 	gen_img(root->exit_x, root->exit_y, root);
// }