#include "fdf.h"

static int do_map(t_point p1, t_point p2)
{
	if (p1.z_origin != p2.z_origin)
	{
		return (GREEN);
	}
	else if (p1.z_origin == 0)
	{
		return (BLUE);
	}
	else
		return (WHITE);
}

int color(t_mlx *param, t_point p1, t_point p2)
{
	if (param->color > RAINBOW)
		param->color = STANDARD;
	if (param->color == MAP)
		return (do_map(p1, p2));
	else if (param->color == RAINBOW)
		return (RED);
	else
		return (WHITE);
}
