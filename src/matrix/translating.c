/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:47:14 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/24 13:46:07 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_matrix(double matrix[4][4], double x, double y, double z)
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = x;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = y;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = z;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	translate(t_mlx *param, double x, double y, double z)
{
	double	matrix[4][4];

	translate_matrix(matrix, x, y, z);
	m_to_point(param, matrix);
}

void	reset_translate(t_mlx *param)
{
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
}
