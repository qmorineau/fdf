/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:04:16 by quentin           #+#    #+#             */
/*   Updated: 2024/11/28 23:51:28 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_transform(t_mlx *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img);
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->size_line, &param->endians);
	map_iter(param->map, reset_xyz);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	centered_obj(param);
	init_scaling(param);
	param->transformation->rx = 0;
	param->transformation->ry = 0;
	param->transformation->rz = 0;
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
	do_projection(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
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
	translate(param, param->scale * data->tx / 100,
		param->scale * data->ty / 100, param->scale * data->tz / 100);
}
