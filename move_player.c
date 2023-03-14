/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:19:44 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/14 15:05:05 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	gen_img(int x, int y, t_root *root)
{
	root->img = mlx_xpm_file_to_image(root->mlx, root->texture_path, &root->img_width, &root->img_height);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->img, (x * 64), (y * 64));
}

void	step_move(int x, t_root *root)
{
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
	else
		root->texture_path = root->tile.last_move;
	gen_img(root->pl_x, root->pl_y, root);
}



void	move_player(int x, int y, t_root *root)root->lines
{
	char	next_tile;

	next_tile = root->map_array[root->pl_y + y][root->pl_x + x];

	if (next_tile == root->tile.a_empty || next_tile == root->tile.a_collectable || next_tile == root->tile.a_exit)
	{
		root->texture_path = root->tile.empty;
		gen_img(root->pl_x, root->pl_y, root);
		root->map_array[root->pl_y][root->pl_x] = root->tile.a_empty;
		
		if (next_tile == root->tile.a_collectable)
			root->collected++;
		
		root->pl_x += x;
		root->pl_y += y;
		step_move(x, root);
		
		ft_putnbr(root->collected_sum);
		write(1, " ", 1);
 		
		if (next_tile == root->tile.a_exit && root->collected == root->collected_sum)
		{
			if (root->tile.last_move == root->tile.player_l)
				root->texture_path = root->tile.player_exit_l;
			else if (root->tile.last_move == root->tile.player_r)
				root->texture_path = root->tile.player_exit_r;
			//gen_img(root->pl_x, root->pl_y, root);
		}		

		if (next_tile == root->tile.a_exit && root->collected == root->collected_sum)
				mlx_destroy_window(root->mlx, root->mlx_win);
		
		ft_putnbr(++root->tile.moves);
		write(1, " ", 1);

		ft_putnbr(root->collected);
		write(1, "\n", 1);
		
	}
}
