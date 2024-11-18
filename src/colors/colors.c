#include "fdf.h"

static int test(t_point p1, int axe)
{
	if (axe == X_AXE)
	{
		if ((int) p1.x % 3 == 0)
			return (RED);
		else if ((int) p1.x % 3 == 1)
			return (GREEN);
		else
			return (BLUE);
	}
	else if (axe == Y_AXE)
	{
		if ((int) p1.y % 3 == 0)
			return (RED);
		else if ((int) p1.y % 3 == 1)
			return (GREEN);
		else
			return (BLUE);
	}
	else
	{
		if ((int) p1.z % 3 == 0)
			return (RED);
		else if ((int) p1.z % 3 == 1)
			return (GREEN);
		else
			return (BLUE);
	}
}

static int do_map(t_point p1, t_point p2)
{
	if (p1.z_origin != p2.z_origin)
		return (GREEN);
	else if (p1.z_origin == 0)
		return (BLUE);
	else if (p1.z_origin <= 10)
		return (RED);
	else if (p1.z_origin > 10)
		return (RED);
	else
		return (WHITE);
}

int color(t_mlx *param, t_point p1, t_point p2, int axe)
{
	if (param->color > RAINBOW)
		param->color = STANDARD;
	if (param->color == MAP)
		return (do_map(p1, p2));
	else if (param->color == RAINBOW)
		return (test(p1, axe));
	else
		return (WHITE);
}
