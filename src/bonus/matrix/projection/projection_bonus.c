/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:07 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:41 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	do_projection(t_mlx *param)
{
	if (param->projection > STEREOGRAPHIC)
		param->projection = ORTHOGRAPHIC;
	if (param->projection == ORTHOGRAPHIC)
		orthographic(param);
	else if (param->projection == ISOMETRIC)
		isometric(param);
	else if (param->projection == STEREOGRAPHIC)
		stereographic(param, param->map);
}

void	change_projection(t_mlx *param)
{
	param->projection++;
	if (param->projection > STEREOGRAPHIC)
		param->projection = ISOMETRIC;
	map_iter(param->map, reset_xyz);
	mlx_destroy_image(param->mlx_ptr, param->img);
	first_and_reset_render(param);
}
