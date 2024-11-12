#include "fdf.h"

void rotate_x(t_mlx *param, double angle)
{
	double	rotate[4][4];
	double	radian;

	radian = convert_angle(angle);
	rx_matrix(rotate, radian);
	m_to_point(param, rotate);
}

void rotate_y(t_mlx *param, double angle)
{
	double	rotate[4][4];
	double	radian;

	radian = convert_angle(angle);
	ry_matrix(rotate, radian);
	m_to_point(param, rotate);
}

void rotate_z(t_mlx *param, double	angle)
{
	double	rotate[4][4];
	double	radian;

	radian = convert_angle(angle);
	rz_matrix(rotate, radian);
	m_to_point(param, rotate);
}
