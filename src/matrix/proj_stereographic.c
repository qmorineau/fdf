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
	map = param->map;
	stereo_matrix(matrix);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			longitude = (map[i][j]->x_origin / param->x_max) * convert_angle(360) - convert_angle(180);
			latitude = convert_angle(90) - (map[i][j]->y_origin / param->y_max) * convert_angle(180);
			map[i][j]->x *= cos(latitude) * cos (longitude);
			map[i][j]->y *= cos (latitude) * sin (longitude);
			map[i][j]->z *= sin(latitude);
		}
	}
	m_to_point(param, matrix);
}
