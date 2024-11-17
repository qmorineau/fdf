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

	printf("x = %f, y = %f\n", param->map[param->x_max][0]->x_origin, param->map[0][param->y_max]->y_origin);
	scale_x = WIDTH / (param->map[0][param->x_max]->x);
	scale_y = HEIGHT / (param->map[param->y_max][0]->y);
	//scale_x = WIDTH / (param->x_max + 1); 
	//scale_y = HEIGHT / (param->y_max + 1);

	if (scale_x < scale_y)
		param->scale = scale_x;
	else
		param->scale = scale_y;
	//param->scale *= 100;
	scale_matrix(param, matrix);

	m_to_point(param, matrix);
}

void scaling_percent(t_mlx *param, double percent)
{
	double matrix[4][4];

	param->scale *= percent/100;
	//printf("scale = %f", param->scale);
	scale_matrix(param, matrix);
	m_to_point(param, matrix);
}
