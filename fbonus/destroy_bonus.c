/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:08:20 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/19 17:45:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

int	close_window(t_root *root)
{
	ft_putstr("GAME OVER\n");
	mlx_destroy_window(root->mlx, root->mlx_win);
	mlx_destroy_display(root->mlx);
	free_main_array(root);
	free_bonus_array(root);
	free(root->mlx);
	exit(0);
	return (0);
}

void	free_main_array(t_root *root)
{
	int	size;

	size = root->lines - 1;
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
}

void	free_bonus_array(t_root *root)
{
	if (root->texture != NULL)
	{
		free(root->texture);
		free(root->enemy.id);
	}
}
