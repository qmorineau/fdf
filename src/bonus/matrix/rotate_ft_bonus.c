/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ft_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:15 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:49 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(t_mlx *param, int repeat, double matrix[4][4])
{
	double	radian;
	double	angle;

	angle = 1;
	if (param->projection == ISOMETRIC)
		angle = 1;
	else if (param->projection == ORTHOGRAPHIC)
		angle = 90;
	else if (param->projection == STEREOGRAPHIC)
		angle = 3;
	radian = convert_angle(angle * repeat);
	rx_matrix(matrix, radian);
}

void	rotate_y(t_mlx *param, int repeat, double matrix[4][4])
{
	double	radian;
	double	angle;

	if (param->projection == ISOMETRIC)
		angle = 1;
	else if (param->projection == ORTHOGRAPHIC)
		angle = 90;
	else if (param->projection == STEREOGRAPHIC)
		angle = 3;
	radian = convert_angle(angle * repeat);
	ry_matrix(matrix, radian);
}

void	rotate_z(t_mlx *param, int repeat, double matrix[4][4])
{
	double	radian;
	double	angle;

	if (param->projection == ISOMETRIC)
		angle = 1;
	else if (param->projection == ORTHOGRAPHIC)
		angle = 90;
	else if (param->projection == STEREOGRAPHIC)
		angle = 3;
	radian = convert_angle(angle * repeat);
	rz_matrix(matrix, radian);
}
