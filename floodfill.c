/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:03 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/23 23:43:18 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	fill(t_point size, t_point cur, char to_fill, t_root *root)
{
	if (cur.y < 1 || cur.y >= size.y - 1 || cur.x < 1 || cur.x >= size.x - 1 || root->map_check[cur.x][cur.y] == root->tile.a_wall || root->map_check[cur.x][cur.y] == 'F')
		return;

	if (root->map_check[cur.x][cur.y] == root->tile.a_exit)
		root->c_exit++;
	else if (root->map_check[cur.x][cur.y] == root->tile.a_collectable)
		root->c_collectable++;
	else if (root->map_check[cur.x][cur.y] == root->tile.a_player)
		root->c_player++;
	else if (root->map_check[cur.x][cur.y] != root->tile.a_wall && root->map_check[cur.x][cur.y] != 'F' && root->map_check[cur.x][cur.y] != root->tile.a_empty)
		root->c_other++;
	root->map_check[cur.x][cur.y] = 'F';
	fill(size, (t_point){cur.x - 1, cur.y}, to_fill, root);
	fill(size, (t_point){cur.x + 1, cur.y}, to_fill, root);
	fill(size, (t_point){cur.x, cur.y - 1}, to_fill, root);
	fill(size, (t_point){cur.x, cur.y + 1}, to_fill, root);
}

void	flood_fill(t_point ffsize, t_point ffbegin, t_root *root)
{
	fill(ffsize, ffbegin, root->map_check[ffbegin.x][ffbegin.y], root);
}
