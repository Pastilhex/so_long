/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:43:50 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/13 21:44:09 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

char	*gen_walls(t_root *root)
{
	if (root->i == 0 && root->j == 0)
		return (root->tile.wall_top_left);
	else if (root->i == 0 && root->j > 0 && root->j < root->rows - 1)
		return (root->tile.wall_top);
	else if (root->i == 0 && root->j == root->rows - 1)
		return (root->tile.wall_top_right);
	else if (root->i == root->lines - 1 && root->j == 0)
		return (root->tile.wall_bottom_left);
	else if (root->i == root->lines - 1
		&& root->j > 0 && root->j < root->rows - 1)
		return (root->tile.wall_bottom);
	else if (root->i == root->lines - 1 && root->j == root->rows - 1)
		return (root->tile.wall_bottom_right);
	else if (root->j == 0)
		return (root->tile.wall_left);
	else if (root->j == root->rows - 1)
		return (root->tile.wall_right);
	else
		return (root->tile.wall);
}
