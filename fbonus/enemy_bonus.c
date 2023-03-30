/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:00:21 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/30 20:51:51 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void    enemy(int id, int x, int y, t_root *m)
{
	char	next_tile;

	next_tile = m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x];
	if (next_tile != m->tile.a_wall && next_tile != m->tile.a_collectable && next_tile != m->tile.a_exit)
	{
		m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x] = 'X';
		m->texture_path = m->tile.empty;
		gen_img(m->enemy.id[id].x, m->enemy.id[id].y, m);
		printf("%d \n", x);
		if (x == -1)
			m->texture_path = m->texture[1];
		else if (x == 1)
			m->texture_path = m->texture[4];
		else
			m->texture_path = m->enemy.id[id].last_move;
//m->enemy.id[id].dir 
//m->enemy.id[id].last_img + 
		m->texture_path = m->texture[m->enemy.id[id].last_img++];
		m->enemy.id[id].last_move = m->texture_path;
		
		if (m->enemy.id[id].last_img == 8)
				m->enemy.id[id].last_img = 0;
		
		m->map_array[m->enemy.id[id].y][m->enemy.id[id].x] = '0';
		m->enemy.id[id].x += x;
		m->enemy.id[id].y += y;
		gen_img(m->enemy.id[id].x, m->enemy.id[id].y, m);
	}
	if (next_tile == m->tile.a_player)
		close_window(m);
}
