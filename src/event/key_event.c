/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:42:11 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/24 00:57:30 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_xyz(t_point *node)
{
	node->x = node->x_origin;
	node->y = node->y_origin;
	node->z = node->z_origin;
}

void	reset_transform(t_mlx *param)
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
		if (data->rx == 360)
			data->rx = 0;
		rotate_x(param, data->rx);
		if (data->ry == 360)
			data->ry = 0;
		rotate_y(param, data->ry);
		if (data->rz == 360)
			data->rz = 0;
		rotate_z(param, data->rz);
	translate(param, param->scale * data->tx, param->scale * data->ty, param->scale * data->tz);
}

int	handle_keypress(int keycode, t_mlx *param)
{
	if (keycode == X || keycode == Y || keycode == Z)
	{
		if (param->projection != ORTHOGRAPHIC)
		{
			param->key_press = keycode;
			return (0);
		}
	}
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT || keycode == S || keycode == D)
	{
		param->key_press = keycode;
		return (0);
	}
	return (0);
}


/* int test(int keycode, t_mlx *param)
{

} */

int	handle_keyrelease(int keycode, t_mlx *param)
{
	if (keycode == X || keycode == Y || keycode == Z)
	{
		if (param->projection != ORTHOGRAPHIC)
		{
			param->key_press = 0;
			return (0);
		}
	}
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT || keycode == S || keycode == D)
	{
		param->key_press = 0;
		return (0);
	}
	if (param->key_press == 0)
	{
		if (keycode == ESC)
			destroy_window(param);
		if (keycode == X)
			param->transformation->rx++;
		else if (keycode == Y)
			param->transformation->ry++;
		else if (keycode == Z)
			param->transformation->rz++;
		else if (keycode == I)
			scaling_percent(param, 110);
		else if (keycode == O)
			scaling_percent(param, 90);
		else if (keycode == C)
			reset_translate(param);
		else if (keycode == V)
			param->color++;
		else if (keycode == P)
			change_projection(param);
		else if (keycode == R)
		{
			reset_transform(param);
			return (0);
		}
		else
			return (0);
		render_frame(param);
	}
	return (0);
}


int handle_hook(t_mlx *param)
{
	if (param->key_press > 0)
	{
		if (param->key_press == X)
			param->transformation->rx++;
		else if (param->key_press == Y)
			param->transformation->ry++;
		else if (param->key_press == Z)
			param->transformation->rz++;
		else if (param->key_press == UP)
			param->transformation->ty--;
		else if (param->key_press == DOWN)
			param->transformation->ty++;
		else if (param->key_press == LEFT)
			param->transformation->tx--;
		else if (param->key_press == RIGHT)
			param->transformation->tx++;
		else if (param->key_press == S)
			param->z_scale += param->scale / 20;
		else if (param->key_press == D)
			param->z_scale -= param->scale / 20;
		render_frame(param);
	}
	return (0);
}
