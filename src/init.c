/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:07 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/24 23:32:56 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_param_transform(t_mlx *param)
{
	param->transformation = malloc(sizeof(t_transform));
	if (!param->transformation)
	{
		malloc_error();
		return (0);
	}
	param->transformation->rx = 0;
	param->transformation->ry = 0;
	param->transformation->rz = 0;
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
	return (1);
}

void	init_z_min_max(t_mlx *param)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	param->z_min = param->map[0][0]->z_origin;
	param->z_max = param->map[0][0]->z_origin;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			if (param->z_min > param->map[i][j]->z_origin)
				param->z_min = param->map[i][j]->z_origin;
			if (param->z_max < param->map[i][j]->z_origin)
				param->z_max = param->map[i][j]->z_origin;
		}
	}
}

t_mlx	*init_window(char *argv[])
{
	t_mlx	*param;

	param = malloc(sizeof(t_mlx));
	if (!param)
	{
		malloc_error();
		exit(0);
	}
	param->map = NULL;
	param->projection = ISOMETRIC;
	param->color = STANDARD;
	param->transformation = NULL;
	param->key_press = 0;
	if (!parsing(argv, param))
		free_wrong_parsing(param);
	if (!init_param_transform(param))
		free_wrong_parsing(param);
	init_z_min_max(param);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fdf");
	return (param);
}
