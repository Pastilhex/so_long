/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:00:21 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/30 07:18:06 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void    enemy(int id, int x, int y, t_root *root)
{
	if (x == -1)
		root->texture_path = root->texture[root->enemy.id[id].last_img + 1];
	else if (x == 1)
		root->texture_path = root->texture[root->enemy.id[id].last_img + 1];
	else
		root->texture_path = root->enemy.last_move;
	root->enemy.last_move = root->texture_path;
	root->enemy.id[id].last_img++;
	if (root->enemy.id[id].last_img == 8)
		root->enemy.id[id].last_img = 0;
	gen_img(root->enemy.id[id].x + x, root->enemy.id[id].y + y, root);
}
