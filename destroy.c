/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:01:12 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/24 12:07:54 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	close_window(t_root *root)
{
	int	size;

	size = root->lines - 1;
	if (root->mlx)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (root->mlx_win)
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
