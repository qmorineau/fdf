/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:37:21 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/24 13:56:21 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include "key.h"
# include "mouse.h"
# include "color.h"

# define HEIGHT 720
# define WIDTH 720
# define DEEP 1000
//# define HEIGHT 1200
//# define WIDTH 1200

# define ISOMETRIC 0
# define ORTHOGRAPHIC 1
# define STEREOGRAPHIC 2

# define X_AXE 0
# define Y_AXE 1
# define Z_AXE 2

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif
 
typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	double		x_origin;
	double		y_origin;
	double		z_origin;
}	t_point;

typedef struct s_transform
{
	int	rx;
	int	ry;
	int	rz;
	int	tx;
	int	ty;
	int	tz;
}	t_transform;

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
	t_transform	*transformation;
	double		scale;
	double		z_scale;
	int			x_max;
	int			y_max;
	int			z_min;
	int			z_max;
	int			key_press;
	int			projection;
	int			color;
}	t_mlx;

/* Transform */
void	apply_transform(t_mlx *param, t_transform *data);
void	reset_transform(t_mlx *param);
/* Bresenham */
void	put_pixel_in_img(t_mlx *param, t_point p, int color);
void	draw_bresenham(t_mlx *param, t_point *p1, t_point *p2);
void	draw_line(t_mlx *param);
/* Map List */
t_point	*map_newpoint(double x, double y, double z);
void	map_clear(t_point ****map);
void	map_iter(t_point ***map, void (*f)(t_point *));
/* Free */
void	free_ptr(char **ptr);
void	free_tab(char ***tab);
void	free_wrong_parsing(t_mlx *param);
/* Parsing */
int		is_fdf_file(char *argv);
int		parsing(char *argv[], t_mlx *all);
/* Colors */
int		color_x(t_mlx *param, t_point p1, t_point p2, int dif);
int		color_y(t_mlx *param, t_point p1, t_point p2, int dif);
int		color_z(t_mlx *param, t_point p1, t_point p2, int dif);
/* Errors */
void	malloc_error(void);
void	wrong_fd_error(void);
/* Rendering */
void	draw_line(t_mlx *param);
void	put_pixel_in_img(t_mlx *param, t_point p, int color);
int		render_frame(t_mlx *param);
/* Init */
t_mlx	*init_window(char *argv[]);
/* Key Event */
int		handle_keyrelease(int keycode, t_mlx *param);
int		handle_keypress(int keycode, t_mlx *param);
int		handle_hook(t_mlx *param);
/* Mouse Event */
int		handle_mouse(int button, int x, int y, t_mlx *param);
/* Close Window */
int		destroy_window(t_mlx *param);
/* Rotate matrix */
void	rx_matrix(double matrix[4][4], double radian);
void	ry_matrix(double matrix[4][4], double radian);
void	rz_matrix(double matrix[4][4], double radian);
void	rotate_x(t_mlx *param, int repeat);
void	rotate_y(t_mlx *param, int repeat);
void	rotate_z(t_mlx *param, int repeat);
/* Center matrix */
void	center_obj_matrix(t_mlx *param, double matrix[4][4]);
void	center_win_matrix(double matrix[4][4]);
void	centered_obj(t_mlx *param);
void	centered_win(t_mlx *param);
/* Projection */
void	do_projection(t_mlx *param);
void	change_projection(t_mlx *param);
/* Matrix */
void	ortho_matrix(double matrix[4][4]);
void	orthographic(t_mlx *param);
void	isometric(t_mlx *param);
void	stereographic(t_mlx *param);
/* Translate matrix */
void	translate_matrix(double matrix[4][4], double x, double y, double z);
void	translate(t_mlx *param, double x, double y, double z);
void	reset_translate(t_mlx *param);
/* Utils matrix */
void	multiply_matrix(double m_a[4][4], double m_b[4][4], double m_c[4][4]);
void	m_to_point(t_mlx *param, double matrix[4][4]);
void	reset_xyz(t_point *node);
double	convert_angle(double angle);
/* Scale matrix */
void	scale_matrix(t_mlx *param, double matrix[4][4]);
void	init_scaling(t_mlx *param);
void	scaling_percent(t_mlx *param, double percent);
#endif
