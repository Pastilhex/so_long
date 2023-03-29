/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:08:20 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/28 21:42:17 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	close_window(t_root *root)
{
	int	size;

	size = root->lines - 1;
	mlx_destroy_window(root->mlx, root->mlx_win);
	mlx_destroy_display(root->mlx);
	if (root->map_array)
	{
		while (size >= 0)
		{
			free(root->map_array[size]);
			free(root->map_check[size--]);
		}
		free(root->map_array);
		free(root->map_check);
	}
	free(root->mlx);
	exit(0);
	return (0);
}
