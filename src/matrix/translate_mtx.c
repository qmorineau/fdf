#include "fdf.h"

void	translate_matrix(double matrix[4][4], double x, double y, double z)
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = x;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = y;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = z;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void translate(t_mlx *param, double x, double y, double z)
{
	double matrix[4][4];

	translate_matrix(matrix, x, y, z);
	m_to_point(param, matrix);
}