/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:23:18 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/24 12:03:15 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

int	handle_no_event(t_root *m)
{
	static int	count;
	int			id;

	count++;
	id = 0;
	if (count == 20000)
		id = enemy_move(id, m);
	if (count % 20000 == 0)
		while (id < m->enemy_sum)
			enemy(id++, 0, 0, m);
	if (count == 60000)
		count = 0;
	return (0);
}

int	handle_keypress(int keysym, t_root *root)
{
	if (keysym == XK_W || keysym == XK_w)
		move_player(0, -1, root);
	else if (keysym == XK_A || keysym == XK_a)
		move_player(-1, 0, root);
	else if (keysym == XK_S || keysym == XK_s)
		move_player(0, 1, root);
	else if (keysym == XK_D || keysym == XK_d)
		move_player(1, 0, root);
	if (keysym == XK_Escape)
		close_window(root);
	return (0);
}

int	enemy_move(int id, t_root *m)
{
	char		next_tile;
	int			x;
	int			y;

	while (id < m->enemy_sum)
	{
		x = enemy_rand();
		y = enemy_rand();
		if (x == -1 || x == 1)
			y = 0;
		if (y == -1 || y == 1)
			x = 0;
		next_tile = m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x];
		if (next_tile != m->tile.a_wall && next_tile != m->tile.a_collectable
			&& next_tile != m->tile.a_exit && next_tile != m->tile.a_enemy)
			enemy(id++, y, x, m);
		if (next_tile == m->tile.a_player)
			close_window(m);
	}
	return (id);
}
