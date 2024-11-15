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
	double ortho[4][4];
	double scaling[4][4];

	t_point ***map;
	int		i;
	int		j;

	i = -1;
	j = 0;
	map = param->map;
	ortho_matrix(ortho);
	scale_matrix(param, scaling);
	multiply_matrix(ortho, scaling, matrix);
	m_to_point(param, matrix);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, map[i][j]->x, map[i][j]->y, 0xFFFFFF);
			j++;
		}
	}
}
