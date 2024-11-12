#include "fdf.h"

void m_to_point(t_mlx *param, double matrix[4][4])
{
	t_point ***map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = param->map;
	while (map[i])
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
			printf("map: i = %d, j = %d, x = %f, y = %f, z = %f\n", i, j, map[i][j]->x, map[i][j]-> y, map[i][j]->z);
			j++;
		}
		i++;
	}
		printf("\n");
}

void multiply_matrix(double m_a[4][4], double m_b[4][4], double m_c[4][4])
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			m_c[i][j] = 0;
			while (k < 4)
			{
				m_c[i][j] += (m_a[i][k] * m_b[k][j]);
				k++;
			}
			j++;
		}
		i++;
	}
}

void scaling(t_mlx *param)
{
	double matrix[4][4];

	scale_matrix(matrix, param->scale);
	m_to_point(param, matrix);
	printf("after scaling\n");
}

void centered_win_obj(t_mlx *param)
{
	double center_obj[4][4];
	double center_win[4][4];
	double matrix[4][4];

	center_obj_matrix(param, center_obj);
	center_win_matrix(center_win);
	multiply_matrix(center_obj, center_win, matrix);
	m_to_point(param, matrix);
}

void decentered_win_obj(t_mlx *param)
{
	double decenter_obj[4][4];
	double decenter_win[4][4];
	double matrix[4][4];

	decenter_obj_matrix(param, decenter_obj);
	decenter_win_matrix(decenter_win);
	multiply_matrix(decenter_obj, decenter_win, matrix);
	m_to_point(param, matrix);
}

void rotate_x(t_mlx *param, double angle)
{
	double	rotate[4][4];
	double	radian;
	//double	tmp;

	//tmp = param->scale;
	//param->scale /= tmp;
	radian = convert_angle(angle);
	//scaling(param);
	rx_matrix(rotate, radian);
	decentered_win_obj(param);
	m_to_point(param, rotate);
	//param->scale *= tmp;
	//scaling(param);
	centered_win_obj(param);
}

void rotate_y(t_mlx *param, double angle)
{
	double	rotate[4][4];
	double	radian;

	radian = convert_angle(angle);
	ry_matrix(rotate, radian);
	decentered_win_obj(param);
	m_to_point(param, rotate);
	centered_win_obj(param);
}

void rotate_z(t_mlx *param, double	angle)
{
	double	rotate[4][4];
	double	radian;

	radian = convert_angle(angle);
	ry_matrix(rotate, radian);
	decentered_win_obj(param);
	m_to_point(param, rotate);
	centered_win_obj(param);
}

void orthographic(t_mlx *param)
{
	double matrix[4][4];

	ortho_matrix(matrix);
	m_to_point(param, matrix);
}