/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:44:20 by quentin           #+#    #+#             */
/*   Updated: 2024/11/27 16:31:58 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render_frame(t_mlx *param)
{
	double	tmp1[4][4];
	double	tmp2[4][4];
	double	tmp3[4][4];

	mlx_destroy_image(param->mlx_ptr, param->img);
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->size_line, &param->endians);
	map_iter(param->map, reset_xyz);
	if (param->projection != STEREOGRAPHIC)
	{
		apply_transform(param, param->transformation, tmp2);
		scale_matrix(param, tmp1);
		multiply_matrix(tmp2, tmp1, tmp3);
		center_obj_matrix(param, tmp2);
		multiply_matrix(tmp3, tmp2, tmp1);
		m_to_point(param, tmp1);
	}
	do_projection(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
	return (0);
}

void	put_pixel_in_img(t_mlx *param, t_point p, int color)
{
	char	*dst;

	if (param->projection != STEREOGRAPHIC)
	{
		(void) color;
		dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
		*(unsigned int *)dst = color;
	}
	else if (p.z <= 0)
	{
		(void) color;
		dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
		*(unsigned int *)dst = color;
	}
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
			x++;
		}
		y++;
	}
}
