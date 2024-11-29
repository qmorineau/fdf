/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:42:11 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/29 13:27:50 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	reset_key(t_mlx *param)
{
	if (param->key_press != 0)
	{
		param->key_press = 0;
		render_frame(param);
	}
	return (0);
}

int	handle_keypress(int keycode, t_mlx *param)
{
	if (keycode == ESC)
		destroy_window(param);
	else if (keycode == X || keycode == Y
		|| keycode == Z || keycode == S || keycode == I)
		param->key_press = keycode;
	else if (keycode == R)
		reset_transform(param);
	else if (keycode == C)
		reset_translate(param);
	else if (keycode == V)
		param->color++;
	else if (keycode == P)
		change_projection(param);
	else if (keycode == UP)
		param->transformation->ty--;
	else if (keycode == DOWN)
		param->transformation->ty++;
	else if (keycode == LEFT)
		param->transformation->tx--;
	else if (keycode == RIGHT)
		param->transformation->tx++;
	else
		return (reset_key(param));
	return (render_frame(param));
}

