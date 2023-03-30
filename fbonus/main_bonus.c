/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:15:36 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/30 15:43:57 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void	start_window(t_root *root)
{
	root->mlx = mlx_init();
	root->mlx_win = mlx_new_window
		(root->mlx, (root->columns * 64), (root->lines * 64), "So Long");
	root->img = mlx_new_image(root->mlx, (root->columns * 64), (root->lines * 64));
	root->addr = mlx_get_data_addr
		(root->img, &root->bits_per_pixel, &root->line_length, &root->endian);
	mlx_destroy_image(root->mlx, root->img);
}

int	main(int argc, char **argv)
{
	t_root	root;
	t_point	ffsize;
	t_point	ffbegin;

	root.map_path = argv[argc - 1];
	check_input(root.map_path, &root);
	map_count(&root);
	start_window(&root);
	settings(&root);
	build_array(&root);
	build_copy(&root);
	ffsize = (t_point){root.lines, root.columns};
	ffbegin = (t_point){root.pl_y, root.pl_x};
	map_check(&root, ffsize, ffbegin);
	enemy_images(&root);
	start_img(&root);
	mlx_loop_hook(root.mlx, &handle_no_event, &root);
	mlx_hook(root.mlx_win, 2, 1L << 0, &handle_keypress, &root);
	mlx_hook(root.mlx_win, 17, 0, close_window, &root);
	mlx_loop(root.mlx);
}
