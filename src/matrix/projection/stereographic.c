/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereographic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:35 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/26 22:21:16 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	stereo_matrix(double matrix[4][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = -1;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

static void apply_stereo_matrices(t_mlx *param)
{
	double tmp1[4][4];
	double tmp2[4][4];
	double tmp3[4][4];

	stereo_matrix(tmp1);
	apply_transform(param, param->transformation, tmp2);
	multiply_matrix(tmp1, tmp2, tmp3);
	m_to_point(param, tmp3);
	center_win_matrix(tmp1);
	m_to_point(param, tmp1);
}

void	stereographic(t_mlx *param, t_point ***map)
{
	double	longitude;
	double	latitude;
	int		i;
	int		j;

	map = param->map;
	i = -1;
	map = param->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			longitude = (map[i][j]->x_origin / param->x_max) * convert_angle(360) - convert_angle(180);
			latitude = convert_angle(90) - (map[i][j]->y_origin / param->y_max) * convert_angle(180);
			map[i][j]->x = param->scale * cos(latitude) * cos(longitude);
			map[i][j]->y = param->scale * cos(latitude) * sin(longitude);
			map[i][j]->z = param->scale * sin(latitude);
		}
	}
	apply_stereo_matrices(param);
}

