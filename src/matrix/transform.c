/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:04:16 by quentin           #+#    #+#             */
/*   Updated: 2024/11/24 01:10:45 by quentin          ###   ########.fr       */
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

void apply_transform(t_mlx *param, t_transform *data)
{
		if (data->rx == 360)
			data->rx = 0;
		rotate_x(param, data->rx);
		if (data->ry == 360)
			data->ry = 0;
		rotate_y(param, data->ry);
		if (data->rz == 360)
			data->rz = 0;
		rotate_z(param, data->rz);
	translate(param, param->scale * data->tx, param->scale * data->ty, param->scale * data->tz);
}
