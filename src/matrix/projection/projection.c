/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:07 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/26 17:48:24 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_projection(t_mlx *param)
{
	if (param->projection > STEREOGRAPHIC)
		param->projection = ORTHOGRAPHIC;
	if (param->projection == ORTHOGRAPHIC)
		orthographic(param);
	else if (param->projection == ISOMETRIC)
		isometric(param);
	else if (param->projection == STEREOGRAPHIC)
		stereographic(param);
}

void	change_projection(t_mlx *param)
{
	double matrix[4][4];

	param->projection++;
	if (param->projection > STEREOGRAPHIC)
		param->projection = ISOMETRIC;
	map_iter(param->map, reset_xyz);
	centered_obj(param);
	init_scaling(param);
	apply_transform(param, param->transformation, matrix);
	m_to_point(param, matrix);
	do_projection(param);
	draw_line(param);
}
