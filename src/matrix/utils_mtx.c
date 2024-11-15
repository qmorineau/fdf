#include "fdf.h"

void set_point(t_point *point, double xyz[3])
{
	point->x = xyz[0];
	point->y = xyz[1];
	point->z = xyz[2];
}
void m_to_point(t_mlx *param, double matrix[4][4])
{
	t_point ***map;
	int		i;
	int		j;
	double	xyz[3];

	i = -1;
	j = -1;
	map = param->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			xyz[0] = (matrix[0][0] * map[i][j]->x) + (matrix[0][1]
				* map[i][j]->y) + (matrix[0][2] * map[i][j]->z) + matrix[0][3];
			xyz[1] = (matrix[1][0] * map[i][j]->x) + (matrix[1][1]
				* map[i][j]->y) + (matrix[1][2] * map[i][j]->z) + matrix[1][3];
			xyz[2] = (matrix[2][0] * map[i][j]->x) + (matrix[2][1]
				* map[i][j]->y) + (matrix[2][2] * map[i][j]->z) + matrix[2][3];
			set_point(map[i][j], xyz);
			//printf("x = %f, y = %f, z = %f\n", map[i][j]->x_origin, map[i][j]->y_origin, map[i][j]->z_origin);
		}
	}
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

double convert_angle(double angle)
{
	double radian;

	radian = (M_PI / 180) * angle;
	return (radian);
}

