/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:42:11 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/28 23:48:37 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keycode, t_mlx *param)
{
	if (keycode == ESC)
		destroy_window(param);
	else if (keycode == X || keycode == Y || keycode == Z || keycode == S || keycode == I)
		param->key_press = keycode;
	else if (keycode == R)
	{
		param->key_press = 0;
		reset_transform(param);
	}
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
		return (0);
	return (render_frame(param));
}

