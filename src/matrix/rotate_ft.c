#include "fdf.h"

void rotate_x(t_mlx *param, int repeat)
{
	double	rotate[4][4];
	double	radian;
	double	angle;

	if (param->projection == ORTHOGRAPHIC)
		angle = 10;
	radian = convert_angle(angle * repeat);
	rx_matrix(rotate, radian);
	m_to_point(param, rotate);
}

void rotate_y(t_mlx *param, int repeat)
{
	double	rotate[4][4];
	double	radian;
	double	angle;

	if (param->projection == ORTHOGRAPHIC)
		angle = 10;
	else if (param->projection == ISOMETRIC)
		angle = 35;
	radian = convert_angle(angle * repeat);
	ry_matrix(rotate, radian);
	m_to_point(param, rotate);
}

void rotate_z(t_mlx *param, int repeat)
{
	double	rotate[4][4];
	double	radian;
	double	angle;

	if (param->projection == ORTHOGRAPHIC)
		angle = 10;
	radian = convert_angle(angle * repeat);
	rz_matrix(rotate, radian);
	m_to_point(param, rotate);
}
