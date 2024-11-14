#ifndef FDF_H
#define FDF_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
#include <fcntl.h>
# include "libft.h"
# include "key.h"

# define HEIGHT 720
# define WIDTH 1280
# define DEEP 10000
# define ORTHOGRAPHIC 0
/* # define HEIGHT 1080
# define WIDTH 1920 */

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
} t_point;

typedef struct s_transform
{
	int rx;
	int ry;
	int rz;
} t_transform;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	***map;
	t_transform *transformation;
	double	scale;
	double	center_x;
	double	center_y;
	int		key_press;
	int		projection;
}	t_mlx;

t_point	*map_newpoint(double x, double y, double z);
void	map_clear(t_point ****map);
void	map_iter(t_point ***map, void (*f)(t_point *));

int		parsing(char *argv[], t_mlx *all);

void	free_ptr(char **ptr);
void	free_tab(char **tab);

void draw_line(t_mlx *param);


double	convert_angle(double angle);


/* Init */
t_mlx *init_window(char *argv[]);
/* Rotate matrix */
void 	rx_matrix(double matrix[4][4], double angle);
void	ry_matrix(double matrix[4][4], double angle);
void	rz_matrix(double matrix[4][4], double angle);
void	rotate_x(t_mlx *param, double angle);
void	rotate_y(t_mlx *param, double angle);
void	rotate_z(t_mlx *param, double angle);
/* Center matrix */
void	center_obj_matrix(t_mlx *param, double matrix[4][4]);
void	center_win_matrix(double matrix[4][4]);
void	centered_obj(t_mlx *param);
void	centered_win(t_mlx *param);
/* Projection */
void	ortho_matrix(double matrix[4][4]);
void stereo_matrix(double matrix[4][4]);
void	orthographic(t_mlx *param);
void stereographic(t_mlx *param);
void	do_orthographic(t_mlx *param, int keycode);
/* Translate matrix */
void	t_matrix(double matrix[4][4], double x, double y, double z);
void	translation_matrix(double matrix[4][4]);
/* Utils matrix */
void	multiply_matrix(double m_a[4][4], double m_b[4][4], double m_c[4][4]);
void	m_to_point(t_mlx *param, double matrix[4][4]);
/* Scale matrix */
void	scale_matrix(double matrix[4][4], double scale);
void	scaling_percent(t_mlx *param, double percent);
void	scaling(t_mlx *param);
/* Draw line */
void	draw_bresenham(t_mlx *param, t_point *p1, t_point *p2);
#endif