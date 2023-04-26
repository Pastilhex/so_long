/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:23:18 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/26 14:18:06 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

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
