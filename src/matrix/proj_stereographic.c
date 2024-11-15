#include "fdf.h"

static void stereo_matrix(double matrix[4][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = -1;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void stereographic(t_mlx *param)
{
	double longitude;
	double latitude;
	double matrix[4][4];
	t_point ***map;
	int		i;
	int		j;

	map = param->map;
	i = -1;
	j = 0;
	map = param->map;
	stereo_matrix(matrix);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			longitude = (map[i][j]->x_origin / param->x_max) * convert_angle(360) - convert_angle(180);
			latitude = convert_angle(90) - (map[i][j]->y_origin / param->y_max) * convert_angle(180);
			map[i][j]->x *= cos(latitude) * cos (longitude);
			map[i][j]->y *= cos (latitude) * sin (longitude);
			map[i][j]->z *= sin(latitude);
			map[i][j]->x = (matrix[0][0] * map[i][j]->x) + (matrix[0][1]
				* map[i][j]->y) + (matrix[0][2] * map[i][j]->z) + matrix[0][3];
			map[i][j]->y = (matrix[1][0] * map[i][j]->x) + (matrix[1][1]
				* map[i][j]->y) + (matrix[1][2] * map[i][j]->z) + matrix[1][3];
			map[i][j]->z = (matrix[2][0] * map[i][j]->x) + (matrix[2][1]
				* map[i][j]->y) + (matrix[2][2] * map[i][j]->z) + matrix[2][3];
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, map[i][j]->x / (1 - map[i][j]->z),
					map[i][j]->y / (1 - map[i][j]->z), 0xFFFFFF);
			//printf("x = %f, y = %f\n", map[i][j]->x / (1 - map[i][j]->z), map[i][j]->y / (1 - map[i][j]->z));
			j++;
		}
	}
}
