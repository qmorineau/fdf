#include "fdf.h"

void do_projection(t_mlx *param)
{
	if (param->projection > STEREOGRAPHIC)
		param->projection = ORTHOGRAPHIC;
	if (param->projection == ORTHOGRAPHIC)
		orthographic(param);
	else if (param->projection == ISOMETRIC)
		isometric(param);
	else if (param->projection == STEREOGRAPHIC)
		stereographic(param);
}