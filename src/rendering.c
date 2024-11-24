/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:44:20 by quentin           #+#    #+#             */
/*   Updated: 2024/11/24 22:52:54 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render_frame(t_mlx *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img);
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->size_line, &param->endians);
	map_iter(param->map, reset_xyz);
	centered_obj(param);
	scaling_percent(param, 100);
	apply_transform(param, param->transformation);
	do_projection(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
	return (0);
}

void	put_pixel_in_img(t_mlx *param, t_point p, int color)
{
	char	*dst;

	(void) color;
	dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
	*(unsigned int* )dst = color;
}

void	draw_line(t_mlx *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		x = 0;
		while (param->map[y][x])
		{
			if (param->map[y + 1])
				draw_bresenham(param, param->map[y][x], param->map[y + 1][x]);
			if (param->map[y][x + 1])
				draw_bresenham(param, param->map[y][x], param->map[y][x + 1]);
			//put_pixel_in_img(param, *param->map[y][x], WHITE);
			x++;
		}
		y++;
	}
}
