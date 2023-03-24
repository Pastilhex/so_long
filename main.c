/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:15:36 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/24 00:18:24 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	check_input(char *str)
{
	#define MAP_PATH str;
	int	size;
	char ext[4] = ".ber";
	int i;

	i = 3;
	size = len(str) - 1;
	while (i >= 0)
	{
		if (str[size - i] != ext[i])
			exit(0);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_root	root;
	char *str;

	str = argv[argc - 1];
	check_input(str);
	root.tile.moves = 0;
	root.mlx = mlx_init();
	map_count(&root);
	root.mlx_win = mlx_new_window
		(root.mlx, (root.columns * 64), (root.lines * 64), "So Long Night");
	root.img = mlx_new_image(root.mlx, (root.columns * 64), (root.lines * 64));
	root.addr = mlx_get_data_addr
		(root.img, &root.bits_per_pixel, &root.line_length, &root.endian);
	settings(&root);
	build_array(&root);
	build_copy(&root);
	map_check(&root);
	start_img(&root);
	mlx_loop_hook(root.mlx, &handle_no_event, &root);
	mlx_hook(root.mlx_win, 2, 1L << 0, &handle_keypress, &root);
	mlx_hook(root.mlx_win, 17, 0, close_window, &root);
	mlx_loop(root.mlx);
}
