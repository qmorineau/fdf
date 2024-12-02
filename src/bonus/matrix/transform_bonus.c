/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:04:16 by quentin           #+#    #+#             */
/*   Updated: 2024/12/02 16:00:01 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	reset_transform(t_mlx *param)
{
	param->key_press = 0;
	param->transformation->rx = 0;
	param->transformation->ry = 0;
	param->transformation->rz = 0;
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
	map_iter(param->map, reset_xyz);
	mlx_destroy_image(param->mlx_ptr, param->img);
	first_and_reset_render(param);
}

void	apply_transform(t_mlx *param, t_transform *data, double matrix[4][4])
{
	double	tmp1[4][4];
	double	tmp2[4][4];
	double	tmp3[4][4];

	if (data->rx == 360)
		data->rx = 0;
	if (data->rx == -1)
		data->rx = 359;
	rotate_x(param, data->rx, tmp1);
	if (data->ry == 360)
		data->ry = 0;
	if (data->ry == -1)
		data->ry = 359;
	rotate_y(param, data->ry, tmp2);
	multiply_matrix(tmp1, tmp2, tmp3);
	if (data->rz == 360)
		data->rz = 0;
	if (data->rz == -1)
		data->rz = 359;
	rotate_z(param, data->rz, tmp1);
	multiply_matrix(tmp3, tmp1, matrix);
}
