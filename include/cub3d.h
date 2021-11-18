/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:25:37 by user42            #+#    #+#             */
/*   Updated: 2021/11/18 19:01:04 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"

typedef struct s_tools
{
	int			keyup;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr_no;
	void		*img_ptr_so;
	void		*img_ptr_ea;
	void		*img_ptr_we;
	void		*img_ptr_sp;
	void		*texture;
	void		*img_ptrnew;
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	char		*sprite_path;
	int			sprite_col;
	int			sprite_row;
	char		**map;
	int			res_x;
	int			res_y;
	int			f_color;
	int			c_color;
	int			width;
	int			height;
	char		*title;
	int			keyleft;
	int			keydown;
	int			keyright;
	double		speed;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		time;
	double		oldtime;
	int			pos_player[2];
	double		dir;
	char		*addr;
	char		*addr_texture;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			bits_per_pixel_2;
	int			line_length_2;
	int			endian_2;
	int			max_y;
	int			case_len;
	int			rotate_left;
	int			rotate_right;
	double		ray_dir;
	double		hit[3];
}				t_tools;

typedef struct s_calcul
{
	int			x_src;
	int			y_src;
	int			x_dest;
	int			y_dest;
	int			color;
	double		fx;
	double		fy;
	int			width;
	int			a;
}				t_calcul;

int				minimize(t_tools *tool);
int				ft_error(int error_code);
int				screen_size(t_tools *tool);
int				get_next_line(int fd, char **line);
void			ft_header(t_tools *tool, int fd);
void			save_screen(t_tools *tool, char *option);
int				quit(t_tools *tool);
void			free_params(char **params);
int				check_path_format(char *path);
double			get_dist_sprite(t_tools *tool, double *hit_x, double hit_y);
double			hit_row_sprite(t_tools *tool, int row, double *hit_x);
void			hit_row_sprite_2(t_tools *tool, int i, int j, double *hit_x);
double			hit_column_sprite(t_tools *tool, int column, double *hit_y);
void			hit_column_sprite_2(t_tools *tool, int i, int j, double *hit_y);
void			hit_sprite(t_tools *tool, int i, int j);
void			rotate_sprite(t_tools *tool, int i, int j);
void			rotate_right(t_tools *tool);
void			rotate_left(t_tools *tool);
void			check_sprite(t_tools *tool);
void			raycasting(t_tools *tool, int sprite);
void			new_calcul(t_tools *tool, int col, int sprite);
double			hit_row(t_tools *tool, int row, double *hit_x);
double			hit_column(t_tools *tool, int column, double *hit_y);
void			get_texture(t_tools *tool, int hit, int sprite);
void			draw_column(double height, int col,
					double hit_x, t_tools *tool);
void			get_img(t_tools *tool, int x, int *y, double height);
unsigned int	get_pixel(t_tools *tool, int x, int y);
void			my_mlx_pixel_put(t_tools *tool, int x, int y, int color);
void			move_right(t_tools *tool);
void			move_left(t_tools *tool);
void			move_backward(t_tools *tool);
void			move_forward(t_tools *tool);
int				main(int ac, char *av[]);
int				release(int keycode, t_tools *tool);
int				press(int keycode, t_tools *tool);
void			move_player(t_tools *tool);
void			init_player_pos(t_tools *tool);
void			create_img_addr(t_tools *tool);
void			init_window(t_tools *tool);
void			init_param(t_tools *tool);
int				hit_right(t_tools *tool);
int				hit_left(t_tools *tool);
int				hit_down(t_tools *tool);
int				hit_up(t_tools *tool);
int				hit_west(t_tools *tool);
int				hit_east(t_tools *tool);
int				hit_south(t_tools *tool);
int				hit_north(t_tools *tool);
double			get_dist(t_tools *tool, double *hit_x, double hit_y);
double			dist(t_tools *tool, double x, double y);
double			ft_round(double n);
int				ft_pair(double n);
void			struct_init(t_tools *tool);
int				check_path_format(char *path);
int				get_north_texture(char **no_texture, t_tools *tool);
int				get_south_texture(char **so_texture, t_tools *tool);
int				get_east_texture(char **ea_texture, t_tools *tool);
int				get_west_texture(char **we_texture, t_tools *tool);
int				get_sprite(char **sprite, t_tools *tool);
int				get_rgb(char *colors);
int				get_ground_color(char **ground, t_tools *tool);
int				get_top_color(char **top, t_tools *tool);
int				get_res(char **res, t_tools *tool);
int				param_check(char **params, t_tools *tool);
int				is_player(char c, t_tools *tool);
int				is_column(char **map, int max, t_tools *tool);
int				is_line(char *str, t_tools *tool);
char			*ft_strcpy_vtwo(char *dest, char *src);
char			*realloc_extended_map(char **str, int max);
int				map_check_line(char *str, t_tools *tool);
int				empty_line(char *str);
int				realloc_map(t_tools *tool);
int				check_player(t_tools *tool, int max_y);
int				map_master_two(int j, int max_x, t_tools *tool);
int				skip_empty_lines(int fd, char **line);
int				map_master(int fd, t_tools *tool);
int				get_map_param(char *path, t_tools *tool);
int				is_all_params_ok(int a);
int				column_plus_or_minus(t_tools *tool, int column);
int				row_plus_or_minus(t_tools *tool, int row);

#endif
