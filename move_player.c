/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:19:44 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/14 22:04:18 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	gen_img(int x, int y, t_root *root)
{
	root->img = mlx_xpm_file_to_image(root->mlx, root->texture_path, &root->img_width, &root->img_height);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->img, (x * 64), (y * 64));
}

void	first_move(char next_tile, int x, int y, t_root *root)
{
	if (next_tile == root->tile.a_collectable)
		++root->collected;
	root->pl_x += x;
	root->pl_y += y;
	if (x == -1)
	{
		root->texture_path = root->tile.player_r;
		root->tile.last_move = root->tile.player_r;
	}
	else if (x == 1)
	{
		root->texture_path = root->tile.player_l;
		root->tile.last_move = root->tile.player_l;
	}
	else if (root->texture_path != root->tile.player_l && root->texture_path != root->tile.player_r)
	{
		root->texture_path = root->tile.player_r;
		root->tile.last_move = root->tile.player_r;
	}
	else
		root->texture_path = root->tile.last_move;
	gen_img(root->pl_x, root->pl_y, root);
	ft_putnbr(++root->tile.moves);
	write(1, "\n", 1);
}

void	second_move(int x, int y, t_root *root)
{
	root->tile.exit_flag = 1;
	root->map_array[root->pl_y][root->pl_x] = root->tile.a_empty;
	root->texture_path = root->tile.empty;
	gen_img(root->pl_x, root->pl_y, root);
	root->pl_x += x;
	root->pl_y += y;
	if (x == -1)
	{
		root->texture_path = root->tile.exit_over_l;
		root->tile.last_move = root->tile.exit_over_l;
	}
	else if (x == 1)
	{
		root->texture_path = root->tile.exit_over_r;
		root->tile.last_move = root->tile.exit_over_r;
	}
	else if (y == -1 || y == 1)
	{
		if (root->tile.last_move == root->tile.player_l)
			root->texture_path = root->tile.exit_over_r;
		else
			root->texture_path = root->tile.exit_over_l;
	}
	ft_putnbr(++root->tile.moves);
	write(1, "\n", 1);
}

void	third_move(int x, int y, t_root *root)
{
	root->map_array[root->pl_y][root->pl_x] = root->tile.a_exit;
	root->texture_path = root->tile.exit;
	gen_img(root->pl_x, root->pl_y, root);
	root->pl_x += x;
	root->pl_y += y;
	if (y == -1 || y == 1)
	{
		if (root->tile.last_move == root->tile.exit_over_l)
			root->texture_path = root->tile.player_l;
		else if (root->tile.last_move == root->tile.exit_over_r)
			root->texture_path = root->tile.player_r;
		else
			root->texture_path = root->tile.last_move;
	}
	else if (x == -1)
		root->texture_path = root->tile.player_r;
	else if (x == 1)
		root->texture_path = root->tile.player_l;
	ft_putnbr(++root->tile.moves);
	write(1, "\n", 1);
}

void	move_player(int x, int y, t_root *root)
{
	char	next_tile;

	next_tile = root->map_array[root->pl_y + y][root->pl_x + x];
	if ((next_tile == root->tile.a_empty || next_tile == root->tile.a_collectable) && root->tile.exit_flag == 0)
	{
		root->map_array[root->pl_y][root->pl_x] = root->tile.a_empty;
		root->texture_path = root->tile.empty;
		gen_img(root->pl_x, root->pl_y, root);
		first_move(next_tile, x, y, root);
	}
	if (next_tile == root->tile.a_exit)
	{
		second_move(x, y, root);
		gen_img(root->pl_x, root->pl_y, root);
	}
	if ((next_tile == root->tile.a_empty || next_tile == root->tile.a_collectable) && root->tile.exit_flag == 1)
	{
		third_move(x, y, root);
		gen_img(root->pl_x, root->pl_y, root);
		root->tile.exit_flag = 0;
	}
}
