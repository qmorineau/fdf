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

void	origin_matrix(t_mlx *param, double matrix[4][4]);
void	origin_undo_matrix(t_mlx *param, double matrix[4][4]);
void 	rx_matrix(double matrix[4][4], double angle);
void	ry_matrix(double matrix[4][4], double angle);
void	rz_matrix(double matrix[4][4], double angle);
void	t_matrix(double matrix[4][4], double x, double y, double z);
void	s_matrix(double matrix[4][4], double x, double y, double z);
void	scale_matrix(double matrix[4][4], double scale);
void	center_matrix(double matrix[4][4], t_mlx *param);
void	translation_matrix(double matrix[4][4]);
void	multiply_matrix(double m_a[4][4], double m_b[4][4], double m_c[4][4]);
#endif