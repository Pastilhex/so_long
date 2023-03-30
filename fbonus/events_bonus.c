/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:23:18 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/30 07:19:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

int	handle_no_event(t_root *root)
{
	static int 	count;
	int			id;

	count++;
	id = 0;
	if (count == 1)
	{
		while (id < root->enemy_sum)
		{
			enemy(id, enemy_step(), enemy_step(), root);
			id++;
		}
	}
	id = 0;
	if (count == 25000)
	{
		while (id < root->lines)
		{
			enemy(id, enemy_step(), enemy_step(), root);
			id++;
		}
	}
	id = 0;
	if (count == 50000)
	{
		while (id < root->lines)
		{
			enemy(id, enemy_step(), enemy_step(), root);
			id++;
		}
	}
	id = 0;
	if (count == 75000)
	{
		while (id < root->lines)
		{
			enemy(id, enemy_step(), enemy_step(), root);
			id++;
		}
	}
	id = 0;
	if (count == 100000)
		count = 0;	
	return (0);
}

int	mouse_event(int keycode, t_root *root)
{
	(void) root;
	if (keycode == 1)
		printf("MOUSE_LEFT_BUTTON\n");
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
