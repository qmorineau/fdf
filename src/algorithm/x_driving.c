/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_driving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:09:35 by quentin           #+#    #+#             */
/*   Updated: 2024/11/27 16:30:13 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	x_driving_1(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int	param1;
	int	param2;

	param1 = 2 * d_s_xyz[0][1] - d_s_xyz[0][0];
	param2 = 2 * d_s_xyz[0][2] - d_s_xyz[0][0];
	if (floor(p1.x) == floor(p2.x))
		return ;
	while (floor(p1.x) <= floor(p2.x))
	{
		p1.x += d_s_xyz[1][0];
		if (param1 >= 0)
		{
			p1.y += d_s_xyz[1][1];
			param1 -= 2 * d_s_xyz[0][0];
		}
		if (param2 >= 0)
		{
			p1.z += d_s_xyz[1][2];
			param2 -= 2 * d_s_xyz[0][0];
		}
		param1 += 2 * d_s_xyz[0][1];
		param2 += 2 * d_s_xyz[0][2];
		if (p1.x > 0 && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			put_pixel_in_img(param, p1, color_x(param, p1, p2, d_s_xyz[0][0]));
	}
}

static void	x_driving_2(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int	param1;
	int	param2;

	param1 = 2 * d_s_xyz[0][1] - d_s_xyz[0][0];
	param2 = 2 * d_s_xyz[0][2] - d_s_xyz[0][0];
	if (floor(p1.x) == floor(p2.x))
		return ;
	while (floor(p1.x) >= floor(p2.x))
	{
		p1.x += d_s_xyz[1][0];
		if (param1 >= 0)
		{
			p1.y += d_s_xyz[1][1];
			param1 -= 2 * d_s_xyz[0][0];
		}
		if (param2 >= 0)
		{
			p1.z += d_s_xyz[1][2];
			param2 -= 2 * d_s_xyz[0][0];
		}
		param1 += 2 * d_s_xyz[0][1];
		param2 += 2 * d_s_xyz[0][2];
		if (p1.x > 0 && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			put_pixel_in_img(param, p1, color_x(param, p1, p2, d_s_xyz[0][0]));
	}
}

void	x_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	{
		if (floor(p1.x) < floor(p2.x))
			x_driving_1(param, d_s_xyz, p1, p2);
		else
			x_driving_2(param, d_s_xyz, p1, p2);
	}
}
