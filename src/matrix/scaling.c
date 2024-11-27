/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:47 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/27 16:17:36 by qmorinea         ###   ########.fr       */
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
	param->z_scale = (param->scale / (param->z_max - param->z_min)) * 10;
	if (param->projection == ISOMETRIC || param->projection == ORTHOGRAPHIC)
	{
		param->scale *= 200;
		param->z_scale *= 200;
		printf("%f\n", param->z_scale);
	}
	else if (param->projection == STEREOGRAPHIC)
	{
		param->scale *= fmax(param->x_max, param->y_max) / 5;
		param->z_scale *= fmax(param->x_max, param->y_max) / 5;
	}
	scale_matrix(param, matrix);
	m_to_point(param, matrix);
}

void	scaling_percent(t_mlx *param, double percent)
{
	double	matrix[4][4];

	param->scale *= percent / 100;
	param->z_scale *= percent / 100;
	scale_matrix(param, matrix);
	m_to_point(param, matrix);
}
