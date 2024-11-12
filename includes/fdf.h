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

# define HEIGHT 360
# define WIDTH 640

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif
 
typedef struct s_point
{
	double		x;
	double		y;
	double		z;
} t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	***map;
	double	scale;
	double	center_x;
	double	center_y;
}	t_mlx;

t_point	*map_newpoint(double x, double y, double z);
void	map_clear(t_point ****map);
void	map_iter(t_point ***map, void (*f)(t_point *));

int		parsing(char *argv[], t_mlx *all);

void	free_ptr(char **ptr);
void	free_tab(char **tab);

void	do_origin_matrix(t_mlx *param, double matrix[4][4]);
void	undo_origin_matrix(t_mlx *param, double matrix[4][4]);
void 	rx_matrix(double matrix[4][4], double angle);
void	ry_matrix(double matrix[4][4], double angle);
void	rz_matrix(double matrix[4][4], double angle);
void	ortho_matrix(double matrix[4][4]);
void	t_matrix(double matrix[4][4], double x, double y, double z);
void	scale_matrix(double matrix[4][4], double scale);
void	descale_matrix(double matrix[4][4], double scale);
void	center_matrix(double matrix[4][4], t_mlx *param);
void	decenter_matrix(double matrix[4][4], t_mlx *param);
void	center_obj_matrix(t_mlx *param, double matrix[4][4]);
void	decenter_obj_matrix(t_mlx *param, double matrix[4][4]);
void	center_win_matrix(double matrix[4][4]);
void	decenter_win_matrix(double matrix[4][4]);
void	translation_matrix(double matrix[4][4]);

void	orthographic(t_mlx *param);
void	multiply_matrix(double m_a[4][4], double m_b[4][4], double m_c[4][4]);
void	rotate_x(t_mlx *param, double angle);
void	rotate_y(t_mlx *param, double angle);
void	rotate_z(t_mlx *param, double angle);
void	scaling(t_mlx *param);
void	centered_win_obj(t_mlx *param);
void	decentered_win_obj(t_mlx *param);
double	convert_angle(double angle);
#endif