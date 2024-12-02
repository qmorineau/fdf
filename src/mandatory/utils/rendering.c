/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:44:20 by quentin           #+#    #+#             */
/*   Updated: 2024/12/02 14:02:59 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_frame(t_mlx *param)
{
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img,
			&param->bits_per_pixel, &param->size_line, &param->endians);
	centered_obj(param);
	init_scaling(param);
	isometric(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
}

void	put_pixel_in_img(t_mlx *param, t_point p, int color)
{
	char	*dst;

	(void) color;
	dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
	*(unsigned int *)dst = color;
}
