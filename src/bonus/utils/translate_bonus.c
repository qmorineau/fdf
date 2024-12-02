/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:15:57 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/29 14:15:07 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_translate(t_mlx *param)
{
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
}

void	translate(t_mlx *param)
{
	int	x;
	int	y;
	int	scale_x;
	int	scale_y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		x = 0;
		while (param->map[y][x])
		{
			scale_x = param->scale * param->transformation->tx / 50;
			scale_y = param->scale * param->transformation->ty / 50;
			param->map[y][x]->x += scale_x;
			param->map[y][x]->y += scale_y;
			x++;
		}
		y++;
	}
}
