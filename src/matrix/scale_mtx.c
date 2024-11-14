#include "fdf.h"

void	scale_matrix(double matrix[4][4], double scale)
{
	(void) scale;
	matrix[0][0] = scale;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = scale;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = scale;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void scaling(t_mlx *param)
{
	double matrix[4][4];

	scale_matrix(matrix, param->scale);
	m_to_point(param, matrix);
}

void scaling_percent(t_mlx *param, double percent)
{
	double matrix[4][4];

	param->scale *= percent/100;
	scale_matrix(matrix, param->scale);
	m_to_point(param, matrix);
}
