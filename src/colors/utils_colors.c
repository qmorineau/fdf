/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:31:52 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/29 11:43:27 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_rgb(int red, int green, int blue)
{
	int	color ;

	color = 0;
	color += (red * 65536);
	color += (green * 256);
	color += (blue * 1);
	return (color);
}

void	retrieve_rgb(int color, double rgb[3])
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

int	find_color(int color1, int color2, double gradient_value)
{
	double	rgb1[3];
	double	rgb2[3];
	int		new_color[3];

	retrieve_rgb(color1, rgb1);
	retrieve_rgb(color2, rgb2);
	new_color[0] = next_color(rgb1[0], rgb2[0], gradient_value);
	new_color[1] = next_color(rgb1[1], rgb2[1], gradient_value);
	new_color[2] = next_color(rgb1[2], rgb2[2], gradient_value);
	return (create_rgb(new_color[0], new_color[1], new_color[2]));
}

int	do_transparency(int color)
{
	double	color_rgb[3];
	double	new_color[3];

	retrieve_rgb(color, color_rgb);
	new_color[0] = color_rgb[0] / 3;
	new_color[1] = color_rgb[1] / 3;
	new_color[2] = color_rgb[2] / 3;
	return (create_rgb(new_color[0], new_color[1], new_color[2]));
}
