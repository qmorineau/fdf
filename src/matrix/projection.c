/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:07 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/22 15:46:13 by qmorinea         ###   ########.fr       */
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
