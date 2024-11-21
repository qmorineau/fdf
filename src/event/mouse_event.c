#include "fdf.h"

int handle_mouse(int button, int x, int y, t_mlx *param)
{
	printf("button = %d\n", button);
	printf("x = %d, y = %d\n", x, y);
	if (button == SCROLL_U)
		scaling_percent(param, 110);
	else if (button == SCROLL_D)
		scaling_percent(param, 90);
	return (0);
}