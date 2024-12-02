/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:57 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:36 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	isometric_rotate(t_mlx *param)
{
	double	rx[4][4];
	double	rz[4][4];
	double	tmp[4][4];
	double	ry[4][4];
	double	matrix[4][4];

	rz_matrix(rz, convert_angle(60));
	rx_matrix(rx, convert_angle(35.26));
	multiply_matrix(rz, rx, tmp);
	ry_matrix(ry, convert_angle(-45));
	multiply_matrix(tmp, ry, matrix);
	m_to_point(param, matrix);
}

void	isometric(t_mlx *param)
{
	double	center[4][4];
	double	isometric[4][4];
	double	matrix[4][4];

	isometric_rotate(param);
	center_win_matrix(center);
	ortho_matrix(isometric);
	multiply_matrix(center, isometric, matrix);
	m_to_point(param, matrix);
}
