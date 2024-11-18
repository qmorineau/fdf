#include "fdf.h"

static void	x_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int param1;
	int param2;

	param1 = 2 * d_s_xyz[0][1] - d_s_xyz[0][0];
	param2 = 2 * d_s_xyz[0][2] - d_s_xyz[0][0];
	while((int) p1.x != (int) p2.x)
	{
		p1.x += d_s_xyz[1][0];
		if (param1 >= 0)
		{
			p1.y += d_s_xyz[1][1];
			param1 -= 2 * d_s_xyz[0][0];
		}
		if (param2 >= 0)
		{
			p1.z += d_s_xyz[1][2];
			param2 -= 2 * d_s_xyz[0][0];
		}
		param1 += 2 * d_s_xyz[0][1];
		param2 += 2 * d_s_xyz[0][2];
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, p1.x, p1.y, color(param, p1, p2));
	}
}

static void	y_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int param1;
	int param2;

	param1 = 2 * d_s_xyz[0][0] - d_s_xyz[0][1];
	param2 = 2 * d_s_xyz[0][2] - d_s_xyz[0][1];
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, p1.x, p1.y, color(param, p1, p2));
	while((int) p1.y != (int) p2.y)
	{
		p1.y += d_s_xyz[1][1];
		if (param1 >= 0)
		{
			p1.x += d_s_xyz[1][0];
			param1 -= 2 * d_s_xyz[0][1];
		}
		if (param2 >= 0)
		{
			p1.z += d_s_xyz[1][2];
			param2 -= 2 * d_s_xyz[0][1];
		}
		param1 += 2 * d_s_xyz[0][0];
		param2 += 2 * d_s_xyz[0][2];
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, p1.x, p1.y, color(param, p1, p2));
	}
}

static void	z_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int param1;
	int param2;

	param1 = 2 * d_s_xyz[0][0] - d_s_xyz[0][2];
	param2 = 2 * d_s_xyz[0][1] - d_s_xyz[0][2];
	while((int) p1.z != (int) p2.z)
	{
		p1.z += d_s_xyz[1][2];
		if (param1 >= 0)
		{
			p1.x += d_s_xyz[1][0];
			param1 -= 2 * d_s_xyz[0][2];
		}
		if (param2 >= 0)
		{
			p1.y += d_s_xyz[1][1];
			param2 -= 2 * d_s_xyz[0][2];
		}
		param1 += 2 * d_s_xyz[0][0];
		param2 += 2 * d_s_xyz[0][1];
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, p1.x, p1.y, color(param, p1, p2));
	}
}

static int	calculate_xyz_s(int p1_xyz, int p2_xyz)
{
	if (p2_xyz > p1_xyz)
		return (1);
	else
		return (-1);
}

void draw_bresenham(t_mlx *param, t_point *p1, t_point *p2)
{
	int dif_sign_xyz[2][3];

	dif_sign_xyz[0][0] = abs((int) p2->x - (int) p1->x);
	dif_sign_xyz[0][1] = abs((int) p2->y - (int) p1->y);
	dif_sign_xyz[0][2] = abs((int) p2->z - (int) p1->z);
	dif_sign_xyz[1][0] = calculate_xyz_s(p1->x, p2->x);
	dif_sign_xyz[1][1] = calculate_xyz_s(p1->y, p2->y);
	dif_sign_xyz[1][2] = calculate_xyz_s(p1->z, p2->z);
	if(dif_sign_xyz[0][0] >= dif_sign_xyz[0][1]
		&& dif_sign_xyz[0][0] >= dif_sign_xyz[0][2])
		x_driving(param, dif_sign_xyz, *p1, *p2);
	else if (dif_sign_xyz[0][1] >= dif_sign_xyz[0][0]
		&& dif_sign_xyz[0][1] >= dif_sign_xyz[0][2])
		y_driving(param, dif_sign_xyz, *p1, *p2);
	else
		z_driving(param, dif_sign_xyz, *p1, *p2);
}
