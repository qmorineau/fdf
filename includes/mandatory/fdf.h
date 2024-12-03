/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:37:21 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/03 15:10:01 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <../../mlx.h>
# include <fcntl.h>
# include "libft.h"

# define DEEP 1000
# define HEIGHT 1000
# define WIDTH 1000

# define ESC 65307
# define WHITE 0xFFFFFF

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	double		x_origin;
	double		y_origin;
	double		z_origin;
}	t_point;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	void		*address;
	int			bits_per_pixel;
	int			size_line;
	int			endians;
	t_point		***map;
	double		scale;
	double		z_scale;
	int			x_max;
	int			y_max;
	int			z_min;
	int			z_max;
	int			key_press;
}	t_mlx;

/* Bresenham */
void	draw_line(t_mlx *param);
void	x_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2);
void	y_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2);
void	z_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2);
/* Map List */
t_point	*map_newpoint(double x, double y, double z);
void	map_clear(t_point ****map);
void	map_iter(t_point ***map, void (*f)(t_point *));
/* Free */
void	free_ptr(char **ptr);
void	free_tab(char ***tab);
void	free_wrong_parsing(t_mlx *param);
void	free_gnl(int fd);
/* Parsing */
int		is_fdf_file(char *argv);
int		parsing(char *argv[], t_mlx *all);
/* Errors */
void	malloc_error(void);
void	wrong_fd_error(void);
void	parsing_error(void);
int		args_error(int argc);
/* Rendering */
void	put_pixel_in_img(t_mlx *param, t_point p, int color);
void	render_frame(t_mlx *param);
/* Init */
t_mlx	*init_window(char *argv[]);
/* Key Event */
int		handle_keypress(int keycode, t_mlx *param);
/* Close Window */
int		destroy_window(t_mlx *param);
int		destroy_window_before_loop(t_mlx *param);
/* Rotate matrix */
void	rx_matrix(double matrix[4][4], double radian);
void	ry_matrix(double matrix[4][4], double radian);
void	rz_matrix(double matrix[4][4], double radian);
void	rotate_x(int repeat, double matrix[4][4]);
void	rotate_y(int repeat, double matrix[4][4]);
void	rotate_z(int repeat, double matrix[4][4]);
/* Center matrix */
void	center_win_matrix(double matrix[4][4]);
void	centered_obj(t_mlx *param);
/* Matrix */
void	ortho_matrix(double matrix[4][4]);
void	orthographic(t_mlx *param);
void	isometric(t_mlx *param);
/* Utils matrix */
void	multiply_matrix(double m_a[4][4], double m_b[4][4], double m_c[4][4]);
void	m_to_point(t_mlx *param, double matrix[4][4]);
double	convert_angle(double angle);
/* Scale matrix */
void	init_scaling(t_mlx *param);
#endif
