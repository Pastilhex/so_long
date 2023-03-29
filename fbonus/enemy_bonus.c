/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:00:21 by pastilhex         #+#    #+#             */
/*   Updated: 2023/03/29 22:03:35 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void    enemy(int n, int x, int y, int stage, char *texture, t_root *root)
{
	enemy_images(root);
	if (x == 1)
	    root->enemy.texture = root->tile.right01;
	else if (x == -1)
	    root->enemy.texture = root->tile.left01;
	if (y == 1)
	    root->enemy.texture = root->tile.right01;
	else if (y == -1)
	    root->enemy.texture = root->tile.left01;
	gen_img(root->enemy.enemys[n].x, root->enemy.enemys[n].y, root);
}
