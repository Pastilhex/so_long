/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:01:39 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/24 11:59:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	start_window(t_root *root)
{
	root->mlx = mlx_init();
	root->mlx_win = mlx_new_window
		(root->mlx, (root->columns * 64), (root->lines * 64), "So Long");
	root->img = mlx_new_image(root->mlx,
			(root->columns * 64), (root->lines * 64));
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
	check_square(&root);
	start_window(&root);
	settings(&root);
	build_array(&root);
	build_copy(&root);
	ffsize = (t_point){root.lines, root.columns};
	ffbegin = (t_point){root.pl_y, root.pl_x};
	map_check(&root, ffsize, ffbegin);
	start_img(&root);
	mlx_hook(root.mlx_win, 2, 1L << 0, &handle_keypress, &root);
	mlx_hook(root.mlx_win, 17, 0, close_window, &root);
	mlx_loop(root.mlx);
}
