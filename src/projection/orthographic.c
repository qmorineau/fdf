#include "fdf.h"

void do_orthographic(t_mlx *param, int keycode)
{
	if (keycode == X)
		param->transformation->rx++;
	else if (keycode == Y)
		param->transformation->ry++;
	else if (keycode == Z)
		param->transformation->rx++;
	else
		return ;
	rotate_x(param, 45);
	rotate_y(param, 45);
	orthographic(param);
	draw_line(param);
}