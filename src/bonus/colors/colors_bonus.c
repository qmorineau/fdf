/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:22 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 12:20:13 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	adjust_range(t_mlx *param)
{
	if (param->z_min < 0)
		return (-param->z_min);
	else
		return (param->z_min);
}

static int	do_rainbow(t_mlx *param, int z_origin)
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
	color = (double)(param->z_max + adjust_range(param)) / 7;
	i = 0;
	tmp = color;
	while (z_origin >= tmp)
	{
		tmp += color;
		i++;
	}
	if (i > 6)
		i = 6;
	return (range[i]);
}

static int	do_temp(t_mlx *param, int z_origin)
{
	int		rgb[3];
	double	rgb_bottom[3];
	double	rgb_top[3];
	double	diff_rgb[3];
	int		z_high;	

	(void) param;
	retrieve_rgb(RED, rgb_top);
	retrieve_rgb(BLUE, rgb_bottom);
	diff_rgb[0] = ((rgb_top[0] - rgb_bottom[0])
			/ (param->z_max + adjust_range(param)));
	diff_rgb[1] = ((rgb_top[1] - rgb_bottom[1])
			/ (param->z_max + adjust_range(param)));
	diff_rgb[2] = ((rgb_top[2] - rgb_bottom[2])
			/ (param->z_max + adjust_range(param)));
	z_high = z_origin + adjust_range(param);
	rgb[0] = ((int) z_high * diff_rgb[0]) + rgb_bottom[0];
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
