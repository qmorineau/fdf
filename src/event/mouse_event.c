#include "fdf.h"

int handle_mouse(int button, int x, int y, t_mlx *param)
{
	(void) param;
	printf("button = %d\n", button);
	printf("x = %d, y = %d\n", x, y);
	return (0);
}