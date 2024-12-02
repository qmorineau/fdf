/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereographic_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:35 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:43 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

static void	apply_stereo_matrices(t_mlx *param)
{
	double	tmp1[4][4];
	double	tmp2[4][4];
	double	tmp3[4][4];

	stereo_matrix(tmp1);
	apply_transform(param, param->transformation, tmp2);
	multiply_matrix(tmp1, tmp2, tmp3);
	rx_matrix(tmp1, convert_angle(90));
	multiply_matrix(tmp3, tmp1, tmp2);
	m_to_point(param, tmp2);
	center_win_matrix(tmp1);
	m_to_point(param, tmp1);
}

void	stereographic(t_mlx *param, t_point ***map)
{
	double	longitude;
	double	latitude;
	double	scaling_factor;
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
			longitude = (map[i][j]->x_origin / param->x_max)
				* convert_angle(360) - convert_angle(180);
			latitude = convert_angle(90) - (map[i][j]->y_origin / param->y_max)
				* convert_angle(180);
			scaling_factor = (0.95 + 0.05 * cos(latitude)) * param->scale;
			map[i][j]->x = scaling_factor * cos(latitude) * cos(longitude);
			map[i][j]->y = scaling_factor * cos(latitude) * sin(longitude);
			map[i][j]->z = scaling_factor * sin(latitude);
		}
	}
	apply_stereo_matrices(param);
}
