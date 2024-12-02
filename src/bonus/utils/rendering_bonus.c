/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:44:20 by quentin           #+#    #+#             */
/*   Updated: 2024/12/02 16:00:30 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	add_first_lines(t_mlx *param, void *mlx, void *win)
{
	if (param->projection == ISOMETRIC)
		mlx_string_put(mlx, win, 85, 30, YELLOW, "ISOMETRIC PROJECTION");
	else if (param->projection == ORTHOGRAPHIC)
		mlx_string_put(mlx, win, 78, 30, YELLOW, "ORTHOGRAPHIC PROJECTION");
	else
		mlx_string_put(mlx, win, 73, 30, YELLOW, "STEREOGRAPHIC PROJECTION");
	mlx_string_put(mlx, win, 20, 50, WHITE,
		"Press key, use mouse scroll if mode's enabled:");
	if (param->key_press == X)
		mlx_string_put(mlx, win, 20, 65, GREEN, "Rotate X mode : Enabled");
	else
		mlx_string_put(mlx, win, 20, 65, WHITE, "X => Rotate X axe");
	if (param->key_press == Y)
		mlx_string_put(mlx, win, 20, 80, GREEN, "Rotate Y mode : Enabled");
	else
		mlx_string_put(mlx, win, 20, 80, WHITE, "Y => Rotate Y axe");
	if (param->key_press == Z)
		mlx_string_put(mlx, win, 20, 95, GREEN, "Rotate Z mode : Enabled");
	else
		mlx_string_put(mlx, win, 20, 95, WHITE, "Z => Rotate Z axe");
	if (param->key_press == I)
		mlx_string_put(mlx, win, 20, 110, GREEN, "Zoom mode : Enable");
	else
		mlx_string_put(mlx, win, 20, 110, WHITE, "I => Zoom");
}

void	add_text(t_mlx *param)
{
	void	*mlx;
	void	*win;

	mlx = param->mlx_ptr;
	win = param->win_ptr;
	add_first_lines(param, mlx, win);
	if (param->key_press == S)
		mlx_string_put(mlx, win, 20, 125, GREEN, "Z Scaling mode : Enable");
	else
		mlx_string_put(mlx, win, 20, 125, WHITE, "S => Change Z scaling");
	mlx_string_put(mlx, win, 20, 140, WHITE, "C => Recenter the object");
	mlx_string_put(mlx, win, 20, 155, WHITE, "P => Change the projection");
	mlx_string_put(mlx, win, 20, 170, WHITE, "Arrows => Translate the object");
	mlx_string_put(mlx, win, 20, 185, WHITE, "V => Change colors");
	mlx_string_put(mlx, win, 20, 200, RED, "R => Reset transformations");
}

void	first_and_reset_render(t_mlx *param)
{
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img,
			&param->bits_per_pixel, &param->size_line, &param->endians);
	centered_obj(param);
	init_scaling(param);
	do_projection(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
	add_text(param);
}

int	render_frame(t_mlx *param)
{
	double	tmp1[4][4];
	double	tmp2[4][4];
	double	tmp3[4][4];

	mlx_destroy_image(param->mlx_ptr, param->img);
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img,
			&param->bits_per_pixel, &param->size_line, &param->endians);
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
	add_text(param);
	return (0);
}

void	put_pixel_in_img(t_mlx *param, t_point p, int color)
{
	char	*dst;

	if (param->projection != STEREOGRAPHIC)
	{
		(void) color;
		dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
		if (p.y < 220 && p.x < 320)
			*(unsigned int *)dst = do_transparency(color);
		else
			*(unsigned int *)dst = color;
	}
	else if (p.z <= 0)
	{
		(void) color;
		dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
		if (p.y < 220 && p.x < 320)
			*(unsigned int *)dst = do_transparency(color);
		else
			*(unsigned int *)dst = color;
	}
}
