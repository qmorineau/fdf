#include "fdf.h"

void draw_line(t_mlx *param)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		x = 0;
		while (param->map[y][x])
		{
			/* if (param->map[y + 1])
				draw_bresenham(param, param->map[y][x], param->map[y + 1][x]);
			if (param->map[y][x + 1])
				draw_bresenham(param, param->map[y][x], param->map[y][x + 1]); */
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->map[y][x]->x, param->map[y][x]->y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

/* int key_press(int keycode, t_mlx *param)
{
	printf("keypress\n");
    if (keycode == ESC)
	{
		map_clear(&param->map);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param);
		exit(0);
	}
	else
		param->key_press = keycode;
    return (0);
}

int	key_release(int keycode, t_mlx *param)
{
	printf("keyrelease\n");
	if (keycode == param->key_press)
		param->key_press = 0;
	return (0);
} */

/* int loop_hook(t_mlx *param)
{
	printf("key = %d\n", param->key_press);
	if (param->key_press == UP)
		map_iter(param->map, add_y);
	else if (param->key_press == DOWN)
		map_iter(param->map, del_y);
	else if (param->key_press == LEFT)
		map_iter(param->map, add_x);
	else if (param->key_press == RIGHT)
		map_iter(param->map, del_x);
	else if (param->key_press == X)
		rotate_x(param, 10);
	else if (param->key_press == Y)
		rotate_y(param, 10);
	else if (param->key_press == Z)
		rotate_z(param, 10);
	else if (param->key_press == C)
		centered_obj(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	orthographic(param);
	return (0);
} */



void print(t_point *node)
{
	printf("x=%f, y=%f, z=%f\n", node->x, node->y, node->z);
}

/* int mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param);
{

} */

int main(int argc, char *argv[])
{
	t_mlx *param;

	(void) argc;
	param = init_window(argv);
	centered_obj(param);
	init_scaling(param);
	do_projection(param);
	draw_line(param);
	mlx_key_hook(param->win_ptr, handle_keypress, param);
	mlx_mouse_hook(param->win_ptr, handle_mouse, param);
	//mlx_loop_hook(param->mlx_ptr, test, param);
	mlx_hook(param->win_ptr, 17, 0, destroy_window, &param);
	mlx_loop(param->mlx_ptr);
}
