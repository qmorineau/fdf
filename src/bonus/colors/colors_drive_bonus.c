/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_drive_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:36:27 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:11 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	color_x(t_mlx *param, t_point p2, t_point p1, int dif)
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

int	color_y(t_mlx *param, t_point p2, t_point p1, int dif)
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

int	color_z(t_mlx *param, t_point p2, t_point p1, int dif)
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
