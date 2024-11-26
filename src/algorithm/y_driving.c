/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_driving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:09:31 by quentin           #+#    #+#             */
/*   Updated: 2024/11/26 22:30:08 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	y_driving_1(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int	param1;
	int	param2;

	param1 = 2 * d_s_xyz[0][0] - d_s_xyz[0][1];
	param2 = 2 * d_s_xyz[0][2] - d_s_xyz[0][1];
	while (floor(p1.y) < floor(p2.y))
	{
		p1.y += d_s_xyz[1][1];
		if (param1 >= 0)
		{
			p1.x += d_s_xyz[1][0];
			param1 -= 2 * d_s_xyz[0][1];
		}
		if (param2 >= 0)
		{
			p1.z += d_s_xyz[1][2];
			param2 -= 2 * d_s_xyz[0][1];
		}
		param1 += 2 * d_s_xyz[0][0];
		param2 += 2 * d_s_xyz[0][2];
		if (p1.x > 0 && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			put_pixel_in_img(param, p1, color_y(param, p1, p2, d_s_xyz[0][1]));
	}
}

static void	y_driving_2(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int	param1;
	int	param2;

	param1 = 2 * d_s_xyz[0][0] - d_s_xyz[0][1];
	param2 = 2 * d_s_xyz[0][2] - d_s_xyz[0][1];
	while (floor(p1.y) > floor(p2.y))
	{
		p1.y += d_s_xyz[1][1];
		if (param1 >= 0)
		{
			p1.x += d_s_xyz[1][0];
			param1 -= 2 * d_s_xyz[0][1];
		}
		if (param2 >= 0)
		{
			p1.z += d_s_xyz[1][2];
			param2 -= 2 * d_s_xyz[0][1];
		}
		param1 += 2 * d_s_xyz[0][0];
		param2 += 2 * d_s_xyz[0][2];
		if (p1.x > 0 && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			put_pixel_in_img(param, p1, color_y(param, p1, p2, d_s_xyz[0][1]));
	}
}

void y_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	{
		if (p1.y < p2.y)
			y_driving_1(param, d_s_xyz, p1, p2);
		else
			y_driving_2(param, d_s_xyz, p1, p2);
	}
}
