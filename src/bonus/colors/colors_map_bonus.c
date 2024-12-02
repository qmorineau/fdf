/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:18:51 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:44:47 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_range_map(int upper_range[5], int lower_range[4])
{
	upper_range[0] = DARK_GREEN;
	upper_range[1] = DARKER_GREEN;
	upper_range[2] = DARK_YELLOW;
	upper_range[3] = BROWN;
	upper_range[4] = WHITE;
	lower_range[0] = BLUE;
	lower_range[1] = LOW_DARK_BLUE;
	lower_range[2] = DARK_BLUE;
	lower_range[3] = DARKER_BLUE;
}

static int	do_upper_range(int z_max, int z_origin, int upper_range[5])
{
	double	color;
	double	tmp;
	int		i;

	color = (double) z_max / 11;
	i = 0;
	tmp = color;
	while (z_origin > tmp)
	{
		tmp += color;
		i++;
	}
	if (i > 4)
		return (upper_range[4]);
	return (upper_range[i]);
}

static int	do_lower_range(int z_min, int z_origin, int lower_range[4])
{
	double	color;
	double	tmp;
	int		i;

	color = (double) z_min / 7;
	color *= -1;
	i = 0;
	tmp = color;
	while (abs(z_origin) > tmp)
	{
		tmp += color;
		i++;
	}
	if (i > 3)
		return (lower_range[3]);
	return (lower_range[i]);
}

int	do_map(t_mlx *param, int z_origin)
{
	int		upper_range[5];
	int		lower_range[4];

	create_range_map(upper_range, lower_range);
	if (z_origin == 0)
		return (BLUE);
	else if (z_origin < 0)
		return (do_lower_range(param->z_min, z_origin, lower_range));
	else
		return (do_upper_range(param->z_max, z_origin, upper_range));
}
