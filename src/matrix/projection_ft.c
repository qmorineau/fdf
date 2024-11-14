#include "fdf.h"

void orthographic(t_mlx *param)
{
	double matrix[4][4];

	t_point ***map;
	int		i;
	int		j;

	i = -1;
	j = 0;
	map = param->map;
	ortho_matrix(matrix);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->x = (matrix[0][0] * map[i][j]->x) + (matrix[0][1]
				* map[i][j]->y) + (matrix[0][2] * map[i][j]->z) + matrix[0][3];
			map[i][j]->y = (matrix[1][0] * map[i][j]->x) + (matrix[1][1]
				* map[i][j]->y) + (matrix[1][2] * map[i][j]->z) + matrix[1][3];
			map[i][j]->z = (matrix[2][0] * map[i][j]->x) + (matrix[2][1]
				* map[i][j]->y) + (matrix[2][2] * map[i][j]->z) + matrix[2][3];
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, map[i][j]->x, map[i][j]->y, 0xFFFFFF);
			//printf("x = %f, y = %f\n", x, y);
			//printf("x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			j++;
		}
	}
}

/* void stereographic(t_mlx *param)
{

} */