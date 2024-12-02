/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mtx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:40 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 15:59:52 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rx_matrix(double matrix[4][4], double radian)
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(radian);
	matrix[1][2] = -sin(radian);
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = sin(radian);
	matrix[2][2] = cos(radian);
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	ry_matrix(double matrix[4][4], double radian)
{
	matrix[0][0] = cos(radian);
	matrix[0][1] = 0;
	matrix[0][2] = sin(radian);
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = -sin(radian);
	matrix[2][1] = 0;
	matrix[2][2] = cos(radian);
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	rz_matrix(double matrix[4][4], double radian)
{
	matrix[0][0] = cos(radian);
	matrix[0][1] = -sin(radian);
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = sin(radian);
	matrix[1][1] = cos(radian);
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}
