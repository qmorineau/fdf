/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:36:03 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/24 00:40:33 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_window(t_mlx *param)
{
	mlx_loop_end(param->mlx_ptr);
	mlx_destroy_image(param->mlx_ptr, param->img);
	map_clear(&param->map);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_display(param->mlx_ptr);
	if (param->transformation)
		free(param->transformation);
	param->transformation = NULL;
	free(param->mlx_ptr);
	free(param);
	param = NULL;
	exit(0);
	return (0);
}
