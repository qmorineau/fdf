/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:42:11 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/28 13:00:05 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_key_pressed(int keycode, t_mlx *param)
{
	if (param->key_press > 0)
	{
		if (keycode == X || keycode == Y || keycode == Z)
		{
			if (param->projection != ORTHOGRAPHIC)
			{
				param->key_press = 0;
				return (0);
			}
		}
		else if (keycode == UP || keycode == DOWN || keycode == LEFT
			|| keycode == RIGHT || keycode == S || keycode == D)
		{
			param->key_press = 0;
			return (0);
		}
		return (0);
	}
	return (1);
}

int	handle_keyrelease(int keycode, t_mlx *param)
{
	if (!is_key_pressed(keycode, param))
		return (0);
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
		reset_transform(param);
	render_frame(param);
	return (0);
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
	else if (keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT || keycode == S || keycode == D)
	{
		param->key_press = keycode;
		return (0);
	}
	return (0);
}

void	add_to_scaling_z(t_mlx *param, int sign)
{
	double	tmp;

	if (param->projection != STEREOGRAPHIC)
	{
		tmp = param->scale / 100 * sign;
		param->z_scale += tmp;
	}
}

int	handle_hook(t_mlx *param)
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
			add_to_scaling_z(param, 1);
		else if (param->key_press == D)
			add_to_scaling_z(param, -1);
		render_frame(param);
	}
	return (0);
}
