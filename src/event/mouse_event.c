/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:05 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/28 23:15:08 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_to_scaling_z(t_mlx *param, int sign)
{
	double	tmp;

	if (param->projection != STEREOGRAPHIC)
	{
		tmp = param->scale / 100 * sign;
		param->z_scale += tmp;
	}
}

int	handle_mouse(int button, int x, int y, t_mlx *param)
{
	(void) x;	
	(void) y;
	if (param->key_press == X && button == SCROLL_D)
		param->transformation->rx++;
	else if (param->key_press == X && button == SCROLL_U)
		param->transformation->rx--;
	else if (param->key_press == Y && button == SCROLL_D)
		param->transformation->ry++;
	else if (param->key_press == Y && button == SCROLL_U)
		param->transformation->ry--;
	else if (param->key_press == Z && button == SCROLL_D)
		param->transformation->rz++;
	else if (param->key_press == Z && button == SCROLL_U)
		param->transformation->rz--;
	else if (param->key_press == S && button == SCROLL_D)
		add_to_scaling_z(param, 1);
	else if (param->key_press == S && button == SCROLL_U)
		add_to_scaling_z(param, -1);
	else if (param->key_press == I && button == SCROLL_D)
		scaling_percent(param, 90);
	else if (param->key_press == I && button == SCROLL_U)
		scaling_percent(param, 110);
	else
		return (0);
	return (render_frame(param));
}
