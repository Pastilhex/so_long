/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:00:21 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/01 16:28:01 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void	enemy(int id, int y, int x, t_root *m)
{
	m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x]
		= m->tile.a_enemy;
	m->texture_path = m->tile.empty;
	gen_img(m->enemy.id[id].x, m->enemy.id[id].y, m);
	if (!(m->enemy.id[id].y + y == m->enemy.id[id].y
			&& m->enemy.id[id].x + x == m->enemy.id[id].x))
		m->map_array[m->enemy.id[id].y][m->enemy.id[id].x] = m->tile.a_empty;
	enemy_check_move(id, x, m);
	if (m->enemy.id[id].l_img == 4)
		m->enemy.id[id].l_img = 0;
	if (m->enemy.id[id].r_img == 8)
		m->enemy.id[id].r_img = 4;
	m->enemy.id[id].x += x;
	m->enemy.id[id].y += y;
	gen_img(m->enemy.id[id].x, m->enemy.id[id].y, m);
}

void	enemy_check_move(int id, int x, t_root *m)
{
	if (x == -1)
	{
		m->enemy.id[id].last_img = m->enemy.id[id].l_img;
		m->texture_path = m->texture[m->enemy.id[id].l_img++];
	}
	else if (x == 1)
	{
		m->enemy.id[id].last_img = m->enemy.id[id].r_img;
		m->texture_path = m->texture[m->enemy.id[id].r_img++];
	}
	else
	{
		if (m->enemy.id[id].last_img >= 0 && m->enemy.id[id].last_img <= 3)
			m->texture_path = m->texture[m->enemy.id[id].l_img++];
		else if (m->enemy.id[id].last_img >= 4 && m->enemy.id[id].last_img <= 7)
			m->texture_path = m->texture[m->enemy.id[id].r_img++];
	}
}
