/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:31:36 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/02 17:56:33 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void	enemy_images(t_root *root)
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
		root->tile.score_board = "./textures/score.xpm";
		root->tile.oneup = "./textures/1up.xpm";
		root->tile.insert = "./textures/insert.xpm";
		root->tile.wall_top_left_bonus = "./textures/top_left_bonus.xpm";
		root->tile.wall_top_bonus = "./textures/top_bonus.xpm";
	}
	search_enemy(root);
}

int	enemy_rand(void)
{
	int	num;

	num = rand() % 30;
	if (num >= 0 && num < 15)
		return (-1);
	else if (num >= 15 && num < 20)
		return (0);
	else
		return (1);
}

void	search_enemy_parameters(int n, t_root *root)
{
	root->enemy.id[n].x = root->j;
	root->enemy.id[n].y = root->i;
	root->enemy.id[n].last_img = 0;
	root->enemy.id[n].l_img = 0;
	root->enemy.id[n].r_img = 4;
}

void	search_enemy(t_root *root)
{
	int		n;

	root->i = 0;
	root->j = 0;
	n = 0;
	root->enemy.id = (struct s_enemy *)malloc
		(root->enemy_sum * sizeof(struct s_enemy));
	if (root->enemy.id)
	{
		while (root->i < root->lines && n < root->enemy_sum)
		{
			while (root->map_array[root->i][root->j] != '\n'
				&& root->map_array[root->i][root->j] != '\0'
				&& n < root->enemy_sum)
			{
				if (root->map_array[root->i][root->j] == root->tile.a_enemy)
					search_enemy_parameters(n++, root);
				root->j++;
			}
			root->j = 0;
			root->i++;
		}
	}
}

void	print_moves(t_root *m)
{
	m->enemy.nmoves = ft_itoa_bonus(++m->tile.moves);
	m->enemy.score = ft_itoa_bonus(m->collected * 100);
	m->img = mlx_xpm_file_to_image(m->mlx, m->tile.oneup,
			&m->img_width, &m->img_height);
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 64, 0);
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_xpm_file_to_image(m->mlx, m->tile.insert,
			&m->img_width, &m->img_height);
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img,
		(m->columns - 2) * 64, 0);
	mlx_destroy_image(m->mlx, m->img);
	mlx_string_put(m->mlx, m->mlx_win, 93, 30, 0x00FFFFFF, m->enemy.nmoves);
	if (((m->columns) / 2) % 2 == 0)
		m->enemy.middle = ((m->columns) / 2) * 64 - 32;
	else
		m->enemy.middle = ((m->columns) / 2) * 64;
	m->img = mlx_xpm_file_to_image(m->mlx, m->tile.score_board,
			&m->img_width, &m->img_height);
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, m->enemy.middle, 0);
	mlx_destroy_image(m->mlx, m->img);
	mlx_string_put(m->mlx, m->mlx_win, m->enemy.middle + 25,
		30, 0x00FFFFFF, m->enemy.score);
	free (m->enemy.score);
	free (m->enemy.nmoves);
}
