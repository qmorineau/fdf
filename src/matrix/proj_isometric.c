#include "fdf.h"

static void	iso_matrix(double matrix[4][4])
{
	matrix[0][0] = 1 / sqrt(2);
	matrix[0][1] = 1 / sqrt(2);
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 1 / sqrt(6);
	matrix[1][1] = 1 / sqrt(6);
	matrix[1][2] = -sqrt(2 / 3);
	matrix[1][3] = 0;
	matrix[2][0] = -sqrt(1 / 3);
	matrix[2][1] = 1 / sqrt(3);
	matrix[2][2] = 1 / sqrt(3);
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void isometric(t_mlx *param)
{
	double matrix[4][4];

	iso_matrix(matrix);
	m_to_point(param, matrix);
}
