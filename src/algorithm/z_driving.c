/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_driving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:09:19 by quentin           #+#    #+#             */
/*   Updated: 2024/11/26 22:28:59 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	z_driving_1(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int	param1;
	int	param2;

	param1 = 2 * d_s_xyz[0][0] - d_s_xyz[0][2];
	param2 = 2 * d_s_xyz[0][1] - d_s_xyz[0][2];
	while (floor(p1.z) < floor(p2.z))
	{
		p1.z += d_s_xyz[1][2];
		if (param1 >= 0)
		{
			p1.x += d_s_xyz[1][0];
			param1 -= 2 * d_s_xyz[0][2];
		}
		if (param2 >= 0)
		{
			p1.y += d_s_xyz[1][1];
			param2 -= 2 * d_s_xyz[0][2];
		}
		param1 += 2 * d_s_xyz[0][0];
		param2 += 2 * d_s_xyz[0][1];
		if (p1.x > 0 && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			put_pixel_in_img(param, p1, color_z(param, p1, p2, d_s_xyz[0][2]));
	}
}

static void	z_driving_2(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	int	param1;
	int	param2;
	
	param1 = 2 * d_s_xyz[0][0] - d_s_xyz[0][2];
	param2 = 2 * d_s_xyz[0][1] - d_s_xyz[0][2];
	while (floor(p1.z) > floor(p2.z))
	{
		p1.z += d_s_xyz[1][2];
		if (param1 >= 0)
		{
			p1.x += d_s_xyz[1][0];
			param1 -= 2 * d_s_xyz[0][2];
		}
		if (param2 >= 0)
		{
			p1.y += d_s_xyz[1][1];
			param2 -= 2 * d_s_xyz[0][2];
		}
		param1 += 2 * d_s_xyz[0][0];
		param2 += 2 * d_s_xyz[0][1];
		if (p1.x > 0 && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			put_pixel_in_img(param, p1, color_z(param, p1, p2, d_s_xyz[0][2]));
	}
}

void z_driving(t_mlx *param, int d_s_xyz[2][3], t_point p1, t_point p2)
{
	{
		if (p1.z < p2.z)
			z_driving_1(param, d_s_xyz, p1, p2);
		else
			z_driving_2(param, d_s_xyz, p1, p2);
	}
}
