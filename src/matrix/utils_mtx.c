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
			j++;
		}
		i++;
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
