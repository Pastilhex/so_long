/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:31:36 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/30 20:54:13 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void    enemy_images(t_root *root)
{
	root->texture = (char **)malloc(8 * sizeof(char *));
	if (root->texture)
	{
		root->texture[0] = "./textures/enemy01_l.xpm";
		root->texture[1] = "./textures/enemy02_l.xpm";
		root->texture[2] = "./textures/enemy03_l.xpm";
		root->texture[3] = "./textures/enemy04_l.xpm";
		root->texture[4] = "./textures/enemy01_r.xpm";
		root->texture[5] = "./textures/enemy02_r.xpm";
		root->texture[6] = "./textures/enemy03_r.xpm";
		root->texture[7] = "./textures/enemy04_r.xpm";
	}
	search_enemy(root);
}

int		enemy_srand(void)
{
	time_t	t;

	srand((unsigned) time(&t));
	int	num;
    num = rand() % 3;
	if (num == 2)
		return (-1);
	else
		return (num);
}

int		enemy_rand(void)
{
	int num = rand() % 3;

	if (num >= 2)
		return (-1);
	else
		return (num);
}

void	search_enemy(t_root *root)
{
	int		n;

	root->i = 0;
	root->j = 0;
	n = 0;
	root->enemy.id = (struct s_enemy *)malloc(root->enemy_sum * sizeof(struct s_enemy));
	if (root->enemy.id)
	{
		while (root->i < root->lines && n < root->enemy_sum)
		{
			while (root->map_array[root->i][root->j] != '\n'
				&& root->map_array[root->i][root->j] != '\0'
				&& n < root->enemy_sum)
			{
				if (root->map_array[root->i][root->j] == root->tile.a_enemy)
				{
					root->enemy.id[n].x = root->j;
					root->enemy.id[n].y = root->i;
					root->enemy.id[n].last_img = 0;
					root->enemy.id[n].last_move = root->texture[0];
					n++;
				}
				root->j++;
			}
			root->j = 0;
			root->i++;
		}
	}
}
