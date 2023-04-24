/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:09:52 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/24 12:04:32 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_enemy
{
	int				enemy;
	int				x;
	int				y;
	int				last_x;
	int				last_y;
	int				last_img;
	int				last_move;
	int				l_img;
	int				r_img;
	int				middle;
	char			*nmoves;
	char			*score;
	struct s_enemy	*id;
}	t_enemy;

typedef struct s_tile
{
	char	*empty;
	char	*wall;
	char	*wall_left;
	char	*wall_right;
	char	*wall_top;
	char	*wall_top_bonus;
	char	*wall_top_left;
	char	*wall_top_left_bonus;
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
	char	*score_board;
	char	*oneup;
	char	*insert;
	char	*gameover;
	char	a_empty;
	char	a_wall;
	char	a_collectable;
	char	a_enemy;
	char	a_exit;
	char	a_player;
	int		moves;
	char	m_i;
	char	p_i;
	char	m_j;
	char	p_j;
	int		exit_flag;
	char	*left01;
	char	*left02;
	char	*left03;
	char	*left04;
	char	*right01;
	char	*right02;
	char	*right03;
	char	*right04;
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
	int		n;
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
	char	**texture;
	char	*map_path;
	int		pl_x;
	int		pl_y;
	int		exit_x;
	int		exit_y;
	int		collected;
	int		collected_sum;
	int		enemy_sum;
	int		c_collectable;
	int		c_player;
	int		c_exit;
	int		c_other;
	t_tile	tile;
	t_point	point;
	t_enemy	enemy;
}	t_root;

void	start_window(t_root	*root);
int		close_window(t_root *root);
void	free_main_array(t_root *root);
void	free_bonus_array(t_root *root);
void	enemy(int id, int x, int y, t_root *root);
void	enemy_check_move(int id, int x, t_root *m);
void	enemy_images(t_root *root);
int		enemy_rand(void);
void	search_enemy_parameters(int n, t_root *root);
void	search_enemy(t_root *root);
void	print_moves(t_root *root);
int		enemy_move(int id, t_root *m);
int		handle_keypress(int keysym, t_root *root);
int		handle_no_event(t_root *root);
void	check_input(char *str, t_root *root);
char	*str(char *newvalue, long int n, int count);
char	*ft_itoa_bonus(int n);
int		counter(long int n);
void	map_validate(t_root *root);
void	map_fail(t_root *root, int i);
void	map_counter(t_root *root);
void	map_check(t_root *root, t_point ffsize, t_point ffbegin);
void	map_count(t_root *root);
void	build_array(t_root *root);
void	build_copy(t_root *root);
void	search_player(t_root *root);
char	*gen_walls(t_root *root);
char	*get_next_line(int fd);
void	fill(t_point size, t_point cur, char to_fill, t_root *root);
void	flood_fill(t_point size, t_point begin, t_root *root);
void	collect_count(t_root *root);
void	search_exit(t_root *root);
int		acess_file(t_root *root);
void	gen_img(int x, int y, t_root *root);
void	first_move(char next_tile, int x, int y, t_root *root);
void	second_move(int x, int y, t_root *root);
void	third_move(char next_tile, int x, int y, t_root *root);
void	move_player(int x, int y, t_root *root);
void	settings(t_root *root);
void	start_img(t_root *root);
int		ft_putchar(char c);
int		ft_putnbr(int n);
void	ft_putstr(char *s);
void	check_square(t_root *root);
int		sqr_len(char *word);
void	start_input(t_root *root);
void	check_input(char *str, t_root *root);
void	free_str(t_root *root);

#endif
