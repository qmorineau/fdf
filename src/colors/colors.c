#include "fdf.h"

/* static int test(t_point p1, int axe)
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
} */

/* static int do_map(t_point p1, t_point p2)
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
} */

/* static int do_rainbow(int color1, int color2, int nbr_step, int actual_step)
{

} */
/* 
int color(t_mlx *param, t_point p1, t_point p2, int dif)
{
	if (param->color > RAINBOW)
		param->color = STANDARD;
	if (param->color == MAP)
		return (do_map(p1, p2));
	else if (param->color == RAINBOW)
		return ();
	else
		return (WHITE);
} */

int color_x(t_mlx *param, t_point p1, t_point p2, int dif)
{
	int color1;
	int color2;
	int range_color;

	(void) param;
	(void) dif;
	//printf("diff = %d\n", dif);
	color1 = p1.z_origin;
	color2 = p2.z_origin;
	range_color = color1 - color2;
	(void) range_color;
	return (0xFFFFFF);
}

int color_y(t_mlx *param, t_point p1, t_point p2, int dif)
{
	int color1;
	int color2;
	int range_color;

	(void) param;
	(void) dif;
	//printf("diff = %d\n", dif);
	color1 = p1.z_origin;
	color2 = p2.z_origin;
	range_color = color1 - color2;
	(void) range_color;
	return (0xFFFFFF);
}

int color_z(t_mlx *param, t_point p1, t_point p2, int dif)
{
	int color1;
	int color2;
	int range_color;

	(void) param;
	(void) dif;
	//printf("diff = %d\n", dif);
	color1 = p1.z_origin;
	color2 = p2.z_origin;
	range_color = color1 - color2;
	(void) range_color;
	return (0xFFFFFF);
}