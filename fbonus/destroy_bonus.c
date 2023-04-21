/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:08:20 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/21 17:58:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

int	close_window(t_root *root)
{
	ft_putstr("GAME OVER\n");
	if (root->mlx)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (root->mlx_win)
		mlx_destroy_display(root->mlx);
	free_main_array(root);
	free_bonus_array(root);
	free(root->mlx);
	exit(0);
	return (0);
}

void	free_main_array(t_root *root)
{
	int	size;

	size = root->lines - 1;
	if (root->map_array)
	{
		while (size >= 0)
		{
			free(root->map_array[size]);
			free(root->map_check[size--]);
		}
		free(root->map_array);
		free(root->map_check);
	}
}

void	free_bonus_array(t_root *root)
{
	if (root->texture != NULL)
	{
		free(root->enemy.id);
		free(root->texture);
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
	root->sqr_size = 0;
	root->sqr_flag = 0;
	root->fd = acess_file(root);
	root->str = get_next_line(root->fd);
	root->sqr_size = sqr_len(root->str);
	free(root->str);
	if (root->sqr_size == 0)
		root->sqr_flag = 1;
	else
	{
		while (root->str)
		{
			root->str = get_next_line(root->fd);
			if ((sqr_len(root->str) != root->sqr_size && root->str)
				|| root->sqr_size == 0)
				root->sqr_flag = 1;
			free(root->str);
		}
	}
	if (root->sqr_flag == 1)
	{	
		ft_putstr("Error\nMap is not square!\n");
		close_window(root);
	}
}
