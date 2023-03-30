/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:23:18 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/30 20:45:55 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

int	handle_no_event(t_root *m)
{
	static int 	count;
	int			id;
	int			x;
	int			y;

	count++;
	id = 0;
	if (count == 25000)
	{
		if (!m->enemy.id[id].dir)
			m->enemy.id[id].dir = -1;
		while (id < m->enemy_sum)
		{
			x = enemy_rand();
			y = 0;
			if (x == 0)
				y = enemy_rand();
			m->enemy.id[id].dir = x;
			if (m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x] != m->tile.a_wall
					|| m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x] != m->tile.a_enemy
					|| m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x ] != m->tile.a_collectable
					|| m->map_array[m->enemy.id[id].y + y][m->enemy.id[id].x + x] != m->tile.a_exit)
				enemy(id++, y, x, m);
			count = 0;
		}
	}
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

void	check_input(char *str, t_root *root)
{
	int		size;
	char	*ext;
	int		i;

	i = 3;
	ext = ".ber";
	size = len(str);
	while (i >= 0)
	{
		if (str[size - i - 1] != ext[3 - i])
			map_fail(root, 8);
		i--;
	}
}
