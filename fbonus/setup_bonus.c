/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:53:01 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/30 07:21:49 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void	settings(t_root *root)
{
	root->tile.empty = "./textures/empty.xpm";
	root->tile.wall = "./textures/wall.xpm";
	root->tile.wall_left = "./textures/left.xpm";
	root->tile.wall_right = "./textures/right.xpm";
	root->tile.wall_top = "./textures/top.xpm";
	root->tile.wall_top_left = "./textures/top_left.xpm";
	root->tile.wall_top_right = "./textures/top_right.xpm";
	root->tile.wall_bottom = "./textures/bottom.xpm";
	root->tile.wall_bottom_left = "./textures/bottom_left.xpm";
	root->tile.wall_bottom_right = "./textures/bottom_right.xpm";
	root->tile.collectable = "./textures/collectible.xpm";
	root->tile.exit = "./textures/exit.xpm";
	root->tile.exit_open = "./textures/exit_open.xpm";
	root->tile.exit_over_l = "./textures/player_exit_l.xpm";
	root->tile.exit_over_r = "./textures/player_exit_r.xpm";
	root->tile.player_r = "./textures/player_r.xpm";
	root->tile.player_l = "./textures/player_l.xpm";
	root->tile.a_empty = '0';
	root->tile.a_wall = '1';
	root->tile.a_collectable = 'C';
	root->tile.a_exit = 'E';
	root->tile.a_player = 'P';
	root->tile.a_enemy = 'X';
	root->collected = 0;
	root->tile.exit_flag = 0;
}

void	start_img(t_root *root)
{
	root->i = 0;
	root->j = 0;
	while (root->i < root->lines)
	{
		while (root->map_array[root->i][root->j] != '\n'
			&& root->map_array[root->i][root->j] != '\0')
		{
			if (root->map_array[root->i][root->j] == root->tile.a_empty)
				root->texture_path = root->tile.empty;
			else if (root->map_array[root->i][root->j] == root->tile.a_wall)
				root->texture_path = gen_walls(root);
			else if (root->map_array[root->i][root->j]
				== root->tile.a_collectable)
				root->texture_path = root->tile.collectable;
			else if (root->map_array[root->i][root->j] == root->tile.a_exit)
				root->texture_path = root->tile.exit;
			else if (root->map_array[root->i][root->j] == root->tile.a_player)
				root->texture_path = root->tile.player_r;
			else if (root->map_array[root->i][root->j] == root->tile.a_enemy)
				root->texture_path = root->texture[0];
			gen_img(root->j, root->i, root);
			root->j++;
		}
		root->j = 0;
		root->i++;
	}
	root->tile.last_move = root->tile.player_r;
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		result += ft_putnbr(n / 10);
		result += ft_putchar('8');
	}
	else if (n < 0)
	{
		result += ft_putchar('-');
		result += ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			result += ft_putnbr(n / 10);
		result += ft_putchar((n % 10) + '0');
	}
	return (result);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(1, &s[i++], 1);
}
