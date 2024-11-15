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
			if (param->map[y + 1])
				draw_bresenham(param, param->map[y][x], param->map[y + 1][x]);
			if (param->map[y][x + 1])
				draw_bresenham(param, param->map[y][x], param->map[y][x + 1]);
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

void reset_xyz(t_point *node)
{
	node->x = node->x_origin;
	node->y = node->y_origin;
	node->z = node->z_origin;
}

void apply_transform(t_mlx *param, t_transform *data)
{
	if (data->rx == 36)
		data->rx = 0;
	rotate_x(param, data->rx);
	if (data->ry == 36)
		data->ry = 0;
	rotate_y(param, data->ry);
	if (data->ry == 36)
		data->ry = 0;
	rotate_z(param, data->ry);
	translate(param, param->scale * data->tx, param->scale * data->ty, 0);
}



/* int handle_keypress(int keycode, t_mlx *param)
{
    printf("Key pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		map_clear(&param->map);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param->transformation);
		free(param);
		exit(0);
	}
	else if (keycode == UP)
		scaling_percent(param, 110);
	else if (keycode == DOWN)
		scaling_percent(param, 90);

	else if (keycode == C)
		centered_obj(param);
	map_iter(param->map, reset_xyz);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	centered_obj(param);
	scaling(param);
	centered_win(param);
	apply_transform(param, param->transformation);
	do_projection(param, keycode);
	orthographic(param);
	draw_line(param);
	map_iter(param->map, reset_xyz);
    return (0);
} */



void centering(t_mlx *param)
{
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
}

int handle_keypress(int keycode, t_mlx *param)
{
    printf("Key pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		map_clear(&param->map);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param->transformation);
		free(param);
		exit(0);
	}
	else if (keycode == I)
		scaling_percent(param, 110);
	else if (keycode == O)
		scaling_percent(param, 90);
	else if (keycode == X)
		param->transformation->rx++;
	else if (keycode == Y)
		param->transformation->ry++;
	else if (keycode == Z)
		param->transformation->rx++;
	else if (keycode == C)
		centering(param);
	else if (keycode == P)
		param->projection++;
	else if (keycode == UP)
		param->transformation->ty--;
	else if (keycode == DOWN)
		param->transformation->ty++;
	else if (keycode == LEFT)
		param->transformation->tx--;
	else if (keycode == RIGHT)
		param->transformation->tx++;
	else
		return (0);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	map_iter(param->map, reset_xyz);
	centered_obj(param);
	scaling_percent(param, 100);
	centered_win(param);
	apply_transform(param, param->transformation);
	do_projection(param);
	draw_line(param);
	map_iter(param->map, reset_xyz);
    return (0);
}

int main(int argc, char *argv[])
{
	t_mlx *param;

	(void) argc;
	param = init_window(argv);
	if (!param)
		return (0);
	centered_obj(param);
	init_scaling(param);
	centered_win(param);
	do_projection(param);
	draw_line(param);
	mlx_key_hook(param->win_ptr, handle_keypress, param);
	mlx_loop(param->mlx_ptr);
}


/* int main(int argc, char *argv[])
{
	t_mlx *all;

	(void) argc;
	all = malloc(sizeof(t_mlx));
	if (!all)
		return (0);
	all->map = NULL;
	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, WIDTH, HEIGHT, "fdf");
	if (!all->win_ptr)
		return (free(all), 0);
	all->scale = 10000;
	all->center_x = 0;
	all->center_y = 0;
	all->key_press = 0;
	if (!parsing(argv, all))
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		return(free(all), 0);
	}
	centered_obj(all);
	scaling(all, 0);
	rotate_x(all, 30);
	rotate_y(all, 30);
	centered_win(all);
	orthographic(all);

	printf("1\n");
	mlx_hook(all->win_ptr, KEY_PRESS, 0, key_press, all);
	printf("2\n"); */
	//mlx_hook(all->win_ptr, KEY_RELEASE, 0, key_release, all);
	/* printf("3\n"); */
	/* printf("4\n");
	mlx_loop_hook(all->mlx_ptr, loop_hook, all); 
	mlx_key_hook(all->win_ptr, handle_key, all);
	mlx_loop(all->mlx_ptr);
}
 */