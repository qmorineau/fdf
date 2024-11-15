#include "fdf.h"

static void	ortho_matrix(double matrix[4][4])
{
	double z_near;
	double right;
	double bottom;

	right = WIDTH / 2;
	bottom = HEIGHT / 2;
	z_near = 0.1;
	matrix[0][0] = 2 / (right - -right);
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = -(right + -right) / (right - -right) + right;
	matrix[1][0] = 0;
	matrix[1][1] = -2 / (-bottom - bottom);
	matrix[1][2] = 0;
	matrix[1][3] = -(-bottom + bottom) / (-bottom - bottom) + bottom;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = -2 / (DEEP - z_near);
	matrix[2][3] = ((DEEP + z_near) / (DEEP - z_near)) * -1;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void orthographic(t_mlx *param)
{
	double matrix[4][4];

	ortho_matrix(matrix);
	m_to_point(param, matrix);
}
