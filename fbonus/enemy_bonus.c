/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:00:21 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/30 23:37:09 by ialves-m         ###   ########.fr       */
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
		if (x == -1)
		{
			m->texture_path = m->texture[m->enemy.id[id].l_img];
			if (m->enemy.id[id].l_img == 4)
				m->enemy.id[id].l_img = 0;
			m->texture_path = m->texture[m->enemy.id[id++].l_img];
		}
		else if (x == 1)
		{
			m->texture_path = m->texture[m->enemy.id[id++].r_img];
			if (m->enemy.id[id].r_img == 8)
				m->enemy.id[id].r_img = 4;
		}


		m->enemy.id[id].last_move = m->texture_path;

		m->map_array[m->enemy.id[id].y][m->enemy.id[id].x] = '0';
		m->enemy.id[id].x += x;
		m->enemy.id[id].y += y;
		gen_img(m->enemy.id[id].x, m->enemy.id[id].y, m);
	}
	if (next_tile == m->tile.a_player)
		close_window(m);
}
