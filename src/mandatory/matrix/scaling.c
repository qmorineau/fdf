/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:47 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:53:22 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_matrix(t_mlx *param, double matrix[4][4])
{
	matrix[0][0] = param->scale;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = param->scale;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = param->z_scale;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	init_scaling(t_mlx *param)
{
	double	matrix[4][4];
	double	scale_x;
	double	scale_y;

	scale_x = WIDTH / (param->map[0][param->x_max]->x);
	scale_y = HEIGHT / (param->map[param->y_max][0]->y);
	param->scale = fmin(scale_x, scale_y);
	if (param->z_max - param->z_min == 0)
		param->z_scale = param->scale / 10;
	else
		param->z_scale = (param->scale / (param->z_max - param->z_min)) * 10;
	param->scale *= 200;
	param->z_scale *= 200;
	scale_matrix(param, matrix);
	m_to_point(param, matrix);
}
