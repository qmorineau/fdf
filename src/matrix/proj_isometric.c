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
	t_point ***map;
	int		i;
	int		j;

	i = -1;
	j = 0;
	map = param->map;
	iso_matrix(matrix);
	m_to_point(param, matrix);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			/* map[i][j]->x = (matrix[0][0] * map[i][j]->x) + (matrix[0][1]
				* map[i][j]->y) + (matrix[0][2] * map[i][j]->z) + matrix[0][3];
			map[i][j]->y = (matrix[1][0] * map[i][j]->x) + (matrix[1][1]
				* map[i][j]->y) + (matrix[1][2] * map[i][j]->z) + matrix[1][3];
			map[i][j]->z = (matrix[2][0] * map[i][j]->x) + (matrix[2][1]
				* map[i][j]->y) + (matrix[2][2] * map[i][j]->z) + matrix[2][3]; */
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, map[i][j]->x, map[i][j]->y, 0xFFFFFF);
			//printf("x = %f, y = %f\n", x, y);
			//printf("x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			j++;
		}
	}
}
