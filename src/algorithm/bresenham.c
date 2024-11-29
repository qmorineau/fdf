/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:39:45 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/29 12:29:37 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calculate_xyz_sign(double p1_xyz, double p2_xyz)
{
	if (p1_xyz < p2_xyz)
		return (1);
	else
		return (-1);
}

void	draw_bresenham(t_mlx *param, t_point *p1, t_point *p2)
{
	int	dif_sign_xyz[2][3];

	dif_sign_xyz[0][0] = abs((int) p2->x - (int) p1->x);
	dif_sign_xyz[0][1] = abs((int) p2->y - (int) p1->y);
	dif_sign_xyz[0][2] = abs((int) p2->z - (int) p1->z);
	dif_sign_xyz[1][0] = calculate_xyz_sign(p1->x, p2->x);
	dif_sign_xyz[1][1] = calculate_xyz_sign(p1->y, p2->y);
	dif_sign_xyz[1][2] = calculate_xyz_sign(p1->z, p2->z);
	if (dif_sign_xyz[0][0] >= dif_sign_xyz[0][1]
		&& dif_sign_xyz[0][0] >= dif_sign_xyz[0][2])
		x_driving(param, dif_sign_xyz, *p1, *p2);
	else if (dif_sign_xyz[0][1] >= dif_sign_xyz[0][0]
		&& dif_sign_xyz[0][1] >= dif_sign_xyz[0][2])
		y_driving(param, dif_sign_xyz, *p1, *p2);
	else
		z_driving(param, dif_sign_xyz, *p1, *p2);
}
