/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:15 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 13:54:37 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int repeat, double matrix[4][4])
{
	double	radian;
	double	angle;

	angle = 1;
	radian = convert_angle(angle * repeat);
	rx_matrix(matrix, radian);
}

void	rotate_y(int repeat, double matrix[4][4])
{
	double	radian;
	double	angle;

	angle = 1;
	radian = convert_angle(angle * repeat);
	ry_matrix(matrix, radian);
}

void	rotate_z(int repeat, double matrix[4][4])
{
	double	radian;
	double	angle;

	angle = 1;
	radian = convert_angle(angle * repeat);
	rz_matrix(matrix, radian);
}
