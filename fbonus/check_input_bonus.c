/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:37:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/26 18:02:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

void	start_input(t_root *root)
{
	root->mlx = NULL;
	root->mlx_win = NULL;
	root->map_array = NULL;
	root->map_check = NULL;
	root->texture = NULL;
	root->c_collectable = 0;
	root->c_player = 0;
	root->c_exit = 0;
	root->c_other = 0;
	root->lines = 1;
	root->columns = 0;
	root->tile.moves = 0;
	root->i = 0;
	root->collected = 0;
	root->collected_sum = 0;
}

void	check_input(char *str, t_root *root)
{
	int		size;
	char	*ext;
	int		i;

	root->mlx = NULL;
	root->mlx_win = NULL;
	root->map_array = NULL;
	root->map_check = NULL;
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

int	sqr_len(char *word)
{
	int	i;

	i = 0;
	if (!word)
		return (0);
	while (word[i] && word[i] != '\n')
		i++;
	return (i);
}

void	check_square(t_root *root)
{
	root->sqr_flag = 0;
	root->fd = acess_file(root);
	while (root->str)
	{
		root->str = get_next_line(root->fd);
		if (root->str && sqr_len(root->str) != root->columns)
			root->sqr_flag = 1;
		free(root->str);
	}
	if (root->sqr_flag == 1)
	{
		ft_putstr("Error\nMap is not square!\n");
		close_window(root);
	}
}

void	free_str(t_root *root)
{
	root->str = get_next_line(root->fd);
	free (root->str);
}
