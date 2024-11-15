#include "fdf.h"

int color(t_point p1, t_point p2)
{
	(void) p2;
	if (p1.z_origin != p2.z_origin)
	{
		return (0x00FF00);
	}
	else if (p1.z_origin == 0)
	{
		return (0x0000FF);
	}
	else
		return (0xFFFFFF);
}
