/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:07 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 13:57:33 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	param->key_press = 0;
	if (!parsing(argv, param))
		free_wrong_parsing(param);
	init_z_min_max(param);
	param->mlx_ptr = mlx_init();
	if (!param->mlx_ptr)
		destroy_window_before_loop(param);
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fdf");
	if (!param->win_ptr)
		destroy_window_before_loop(param);
	return (param);
}
