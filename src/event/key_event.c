#include "fdf.h"

void reset_xyz(t_point *node)
{
	node->x = node->x_origin;
	node->y = node->y_origin;
	node->z = node->z_origin;
}

void change_projection(t_mlx *param)
{
	param->projection++;
	if (param->projection > STEREOGRAPHIC)
		param->projection = ISOMETRIC;
}

void reset_transform(t_mlx *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img);
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->size_line, &param->endians);
	map_iter(param->map, reset_xyz);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	centered_obj(param);
	init_scaling(param);
	param->transformation->rx = 0;
	param->transformation->ry = 0;
	param->transformation->rz = 0;
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
	do_projection(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
}

void apply_transform(t_mlx *param, t_transform *data)
{
	if (data->rx == 120)
		data->rx = 0;
	rotate_x(param, data->rx);
	if (data->ry == 120)
		data->ry = 0;
	rotate_y(param, data->ry);
	if (data->ry == 120)
		data->ry = 0;
	rotate_z(param, data->ry);
	translate(param, param->scale * data->tx, param->scale * data->ty, param->scale * data->tz);
}

int handle_keypress(int keycode, t_mlx *param)
{
	printf("key = %d\n", keycode);
	if (keycode == X)
		param->transformation->rx++;
	else if (keycode == Y)
		param->transformation->ry++;
	else if (keycode == Z)
		param->transformation->rx++;
	return (0);
}

int handle_keyrelease(int keycode, t_mlx *param)
{
    printf("Key pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_loop_end(param->mlx_ptr);
		destroy_window(param);
	}
	else if (keycode == I)
		scaling_percent(param, 110);
	else if (keycode == O)
		scaling_percent(param, 90);
	else if (keycode == C)
		reset_translate(param);
	else if (keycode == V)
		param->color++;
	else if (keycode == P)
	{
		change_projection(param);
		map_iter(param->map, reset_xyz);
		centered_obj(param);
		init_scaling(param);
		apply_transform(param, param->transformation);
		do_projection(param);
		draw_line(param);
	}
	else if (keycode == R)
	{
		reset_transform(param);
		return (0);
	}
	else if (keycode == S)
		param->z_scale += param->scale / 20;
	else if (keycode == D)
		param->z_scale -= param->scale / 20;
	else if (keycode == UP)
		param->transformation->ty--;
	else if (keycode == DOWN)
		param->transformation->ty++;
	else if (keycode == LEFT)
		param->transformation->tx--;
	else if (keycode == RIGHT)
		param->transformation->tx++;
    return (0);
}