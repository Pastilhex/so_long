/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:09:52 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/21 17:31:23 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_tile
{
	char	*empty;
	char	*wall;
	char	*wall_left;
	char	*wall_right;
	char	*wall_top;
	char	*wall_top_left;
	char	*wall_top_right;
	char	*wall_bottom;
	char	*wall_bottom_left;
	char	*wall_bottom_right;
	char	*collectable;
	char	*exit;
	char	*exit_open;
	char	*exit_over_l;
	char	*exit_over_r;
	char	*player_r;
	char	*player_l;
	char	*player_exit_r;
	char	*player_exit_l;
	char	*last_move;
	char	a_empty;
	char	a_wall;
	char	a_collectable;
	char	a_exit;
	char	a_player;
	int		moves;
	char	m_i;
	char	p_i;
	char	m_j;
	char	p_j;
	int		exit_flag;
}	t_tile;

typedef struct s_root
{
	int		img_width;
	int		img_height;
	char	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		j;
	int		lines;
	int		columns;
	int		fd;
	int		size;
	int		sqr_size;
	int		sqr_flag;
	char	*str;
	char	**map_array;
	char	**map_check;
	char	tx_replace;
	char	*texture_path;
	char	*map_path;
	int		pl_x;
	int		pl_y;
	int		exit_x;
	int		exit_y;
	int		collected;
	int		collected_sum;
	int		c_collectable;
	int		c_player;
	int		c_exit;
	int		c_other;
	t_tile	tile;
	t_point	point;
}	t_root;

int		close_window(t_root *root);
int		mouse_event(int keycode, t_root *root);
int		handle_keypress(int keysym, t_root *root);
int		handle_no_event(void *root);
void	check_input(char *str, t_root *root);
void	map_fail(t_root *root, int i);
void	map_validate(t_root *root);
void	map_counter(t_root *root);
void	map_check(t_root *root, t_point ffsize, t_point ffbegin);
void	map_count(t_root *root);
void	build_array(t_root *root);
void	build_copy(t_root *root);
void	search_player(t_root *root);
char	*gen_walls(t_root *root);
char	*get_next_line(int fd);
void	gen_img(int x, int y, t_root *root);
void	move_player(int x, int y, t_root *root);
int		ft_putchar(char c);
int		ft_putnbr(int n);
void	ft_putstr(char *s);
void	settings(t_root *root);
void	start_img(t_root *root);
void	flood_fill(t_point size, t_point begin, t_root *root);
void	fill(t_point size, t_point cur, char to_fill, t_root *root);
void	collect_count(t_root *root);
void	search_exit(t_root *root);
int		acess_file(t_root *root);
void	check_square(t_root *root);
int		sqr_len(char *word);

#endif
