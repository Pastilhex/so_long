/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:53:01 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/13 23:37:13 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

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
	root->tile.player_r = "./textures/player_r.xpm";
	root->tile.player_l = "./textures/player_l.xpm";
	root->tile.a_empty = '0';
	root->tile.a_wall = '1';
	root->tile.a_collectable = 'C';
	root->tile.a_exit = 'E';
	root->tile.a_player = 'P';
	root->collected = 0;
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
