/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:22 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/25 15:39:53 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	adjust_range(t_mlx *param)
{
	if (param->z_min < 0)
		return (-param->z_min);
	else
		return (-param->z_min);
}

int	create_rgb(int red, int green, int blue)
{
	int	color ;

	color = 0;
	color += (red * 65536);
	color += (green * 256);
	color += (blue * 1);
	return (color);
}

void	retrieve_rgb(int color, int rgb[3])
{
	if (color > 16777215 || color < 0)
	{
		rgb[0] = -1;
		rgb[1] = -1;
		rgb[2] = -1;
		return ;
	}
	rgb[0] = color / 65536;
	color -= rgb[0] * 65536;
	rgb[1] = color / 256;
	color -= rgb[1] * 256;
	rgb[2] = color;
}

int	do_rainbow(t_mlx *param, int z_origin)
{
	int		range[7];
	double	color;
	double	tmp;
	int		i;

	range[0] = PURPLE;
	range[1] = BLUE;
	range[2] = CYAN;
	range[3] = GREEN;
	range[4] = YELLOW;
	range[5] = ORANGE;
	range[6] = RED;

	z_origin += adjust_range(param);
	color = (double) (param->z_max + adjust_range(param)) / 7;
	i = 0;
	tmp = color;
	while (z_origin > tmp)
	{
		tmp += color;
		i++;
	}
	return (range[i]);
}

int	do_map(t_mlx *param, int z_origin)
{
	int		range[4];
	double	color;
	double	tmp;
	int		i;

	range[0] = GREEN;
	range[1] = YELLOW;
	range[2] = BROWN;
	range[3] = WHITE;

	if (z_origin <= 0)
		return (BLUE);
	else if (z_origin == param->z_max)
		return (WHITE);
	color = (double) param->z_max / 4;
	i = 0;
	tmp = color;
	while (z_origin > tmp)
	{
		tmp += color;
		i++;
	}
	return (range[i]);
}

int	do_temp(t_mlx *param, int z_origin)
{
	int		rgb[3];
	int		rgb_bottom[3];
	int		rgb_top[3];
	int	diff_rgb[3];
	int		z_high;	
	
	(void) param;
	retrieve_rgb(RED, rgb_top);
	retrieve_rgb(BLUE, rgb_bottom);
	diff_rgb[0] = ((rgb_top[0] - rgb_bottom[0]) / (param->z_max + adjust_range(param)));
	diff_rgb[1] = ((rgb_top[1] - rgb_bottom[1]) / (param->z_max + adjust_range(param)));
	diff_rgb[2] = ((rgb_top[2] - rgb_bottom[2]) / (param->z_max + adjust_range(param)));
	z_high = z_origin + adjust_range(param);
	rgb[0] = ((int) z_high * diff_rgb[0]) + rgb_bottom[0];;
	rgb[1] = ((int) z_high * diff_rgb[1]) + rgb_bottom[1];
	rgb[2] = ((int) z_high * diff_rgb[2]) + rgb_bottom[2];
	return (create_rgb(rgb[0], rgb[1], rgb[2]));
}

int	calculate_color(t_mlx *param, int z_origin)
{
	if (param->color > Z_COLOR)
		param->color = STANDARD;
	if (param->color == MAP)
		return (do_map(param, z_origin));
	else if (param->color == TEMP)
		return (do_temp(param, z_origin));
	else if (param->color == RAINBOW)
		return (do_rainbow(param, z_origin));
	else if (param->color == Z_COLOR)
		return (z_origin);
	else
		return (WHITE);
}

int	next_color(int rgb1, int rgb2, double gradient_value)
{
	double	tmp;

	tmp = abs(rgb1 - rgb2);
	tmp *= gradient_value;
	if (rgb1 > rgb2)
		return (rgb1 - (int) tmp);
	else
		return (rgb1 + (int) tmp);
}


int find_color(int color1, int color2, double gradient_value)
{
	int	rgb1[3];
	int	rgb2[3];
	int	new_color[3];

	retrieve_rgb(color1, rgb1);
	retrieve_rgb(color2, rgb2);
	new_color[0] = next_color(rgb1[0], rgb2[0], gradient_value);
	new_color[1] = next_color(rgb1[1], rgb2[1], gradient_value);
	new_color[2] = next_color(rgb1[2], rgb2[2], gradient_value);
	return (create_rgb(new_color[0], new_color[1], new_color[2]));
}

int color_x(t_mlx *param, t_point p2, t_point p1, int dif)
{
	int		color1;
	int		color2;
	int		pxl_to_draw;
	double	tmp;

	color1 = calculate_color(param, p1.z_origin);
	color2 = calculate_color(param, p2.z_origin);
	if (p1.z_origin == p2.z_origin)
		return (color1);
	pxl_to_draw = abs((int) p2.x - (int) p1.x);
	tmp = (double) pxl_to_draw / (double) dif;
	return (find_color(color1, color2, tmp));
}

int color_y(t_mlx *param, t_point p2, t_point p1, int dif)
{
	int		color1;
	int		color2;
	int		pxl_to_draw;
	double	tmp;

	color1 = calculate_color(param, p1.z_origin);
	color2 = calculate_color(param, p2.z_origin);
	if (p1.z_origin == p2.z_origin)
		return (color1);
	pxl_to_draw = abs((int) p2.y - (int) p1.y);
	tmp = (double) pxl_to_draw / (double) dif;
	return (find_color(color1, color2, tmp));
}

int color_z(t_mlx *param, t_point p2, t_point p1, int dif)
{
	int		color1;
	int		color2;
	int		pxl_to_draw;
	double	tmp;

	color1 = calculate_color(param, p1.z_origin);
	color2 = calculate_color(param, p2.z_origin);
	if (p1.z_origin == p2.z_origin)
		return (color1);
	pxl_to_draw = abs((int) p2.z - (int) p1.z);
	tmp = (double) pxl_to_draw / (double) dif;
	return (find_color(color1, color2, tmp));
}