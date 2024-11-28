/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:44:20 by quentin           #+#    #+#             */
/*   Updated: 2024/11/28 17:58:59 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test(t_mlx *param)
{
	if (param->filter)
		mlx_destroy_image(param->mlx_ptr, param->img);
	param->filter = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT / 8);
	param->add = mlx_get_data_addr(param->filter, &param->bpp, &param->l_size, &param->end);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->filter, 0, 0);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 50, RED, "Commands to control the object :");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 70, RED, "X => rotate axe X");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 90, RED, "Y => rotate axe Y");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 110, RED, "z => rotate axe Z");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 130, RED, "I / O / => zoom In/Out");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 150, RED, "Mouse Scroll => Zooms");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 170, RED, "S / D => adjust z_scaling");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 190, RED, "Arrows => translate on axe X & Y");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50, 210, RED, "R => reset");
}

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

	//test(param);

	return (0);
}

int	add_opacity(int color)
{
	return (color);
}

void	put_pixel_in_img(t_mlx *param, t_point p, int color)
{
	char	*dst;

	if (param->projection != STEREOGRAPHIC)
	{
		(void) color;
		dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
		if (p.x <= 200 && p.y <= 200)
			*(unsigned int *)dst = add_opacity(color);
		else
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
