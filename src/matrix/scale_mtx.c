#include "fdf.h"

void	scale_matrix(t_mlx *param, double matrix[4][4])
{
	matrix[0][0] = param->scale;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = param->scale;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = param->scale;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void init_scaling(t_mlx *param)
{
	double matrix[4][4];
	double scale_x;
	double scale_y;

	scale_x = WIDTH / (param->x_max + 1); 
	scale_y = HEIGHT / (param->y_max + 1);

	if (scale_x < scale_y)
		param->scale = scale_x;
	else
		param->scale = scale_y;
	scale_matrix(param, matrix);
	m_to_point(param, matrix);
}

void scaling_percent(t_mlx *param, double percent)
{
	double matrix[4][4];

	param->scale *= percent/100;
	scale_matrix(param, matrix);
	m_to_point(param, matrix);
}
