/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:31:36 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/29 22:03:06 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void    enemy_images(t_root *root)
{
	root->tile.left01 = "../textures/enemy01_l.xpm";
	root->tile.left02 = "../textures/enemy02_l.xpm";
	root->tile.left03 = "../textures/enemy03_l.xpm";
	root->tile.left04 = "../textures/enemy04_l.xpm";
	root->tile.right01 = "../textures/enemy01_l.xpm";
	root->tile.right02 = "../textures/enemy02_l.xpm";
	root->tile.right03 = "../textures/enemy03_l.xpm";
	root->tile.right04 = "../textures/enemy04_l.xpm";
}

void	search_enemy(t_root *root)
{
	int		n;

	root->i = 0;
	root->j = 0;
	n = 0;
	root->enemy.enemys = (struct s_enemy *)malloc(root->enemy_sum * sizeof(struct s_enemy));
	if (root->enemy.enemys)
	{
		while (root->i < root->lines && n < root->enemy_sum)
		{
			while (root->map_array[root->i][root->j] != '\n'
				&& root->map_array[root->i][root->j] != '\0')
			{
				if (root->map_array[root->i][root->j] == root->tile.a_enemy)
				{
					root->enemy.enemys[0].x = root->j;
					root->enemy.enemys[0].y = root->i;
				}
				root->j++;
			}
			root->j = 0;
			root->i++;
		}
	}
}
