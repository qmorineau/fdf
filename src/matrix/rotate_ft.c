/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:15 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/24 11:46:35 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_mlx *param, int repeat)
{
	double	rotate[4][4];
	double	radian;
	double	angle;

	if (param->projection == ISOMETRIC)
		angle = 1;
	else if (param->projection == ORTHOGRAPHIC)
		angle = 90;
	else
		angle = 1;
	radian = convert_angle(angle * repeat);
	rx_matrix(rotate, radian);
	m_to_point(param, rotate);
}

void	rotate_y(t_mlx *param, int repeat)
{
	double	rotate[4][4];
	double	radian;
	double	angle;

	if (param->projection == ISOMETRIC)
		angle = 1;
	else if (param->projection == ORTHOGRAPHIC)
		angle = 90;
	else
		angle = 1;
	radian = convert_angle(angle * repeat);
	ry_matrix(rotate, radian);
	m_to_point(param, rotate);
}

void	rotate_z(t_mlx *param, int repeat)
{
	double	rotate[4][4];
	double	radian;
	double	angle;

	if (param->projection == ISOMETRIC)
		angle = 1;
	else if (param->projection == ORTHOGRAPHIC)
		angle = 90;
	else
		angle = 1;
	radian = convert_angle(angle * repeat);
	rz_matrix(rotate, radian);
	m_to_point(param, rotate);
}
