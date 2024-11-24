/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereographic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:45:35 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/24 12:45:24 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	stereo_matrix(double matrix[4][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = -1;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	test(double matrix[4][4], t_point *point)
{
	double	xyz[3];
	double	w;

	w  = matrix[3][0] * point->x + matrix[3][1]
		* point->y + matrix[3][2] * point->z + matrix[3][3];
	xyz[0] = matrix[0][0] * point->x + matrix[0][1] * point->y
		+ matrix[0][2] * point->z + matrix[0][3] / w;
	xyz[1] = matrix[1][0] * point->x + matrix[1][1] * point->y
		+ matrix[1][2] * point->z + matrix[1][3] / w;
	xyz[2] = matrix[2][0] * point->x + matrix[2][1] * point->y
		+ matrix[2][2] * point->z + matrix[2][3] / w;
	point->x = xyz[0];
	point->y = xyz[1];
	point->z = xyz[2];
}

void	stereographic(t_mlx *param)
{
	double	longitude;
	double	latitude;
	double	scale[4][4];
	//double	tmp[4][4];
	double	center[4][4];
	double	projection[4][4];
	//double	matrix[4][4];
	t_point	***map;
	int		i;
	int		j;

	map = param->map;
	i = -1;
	map = param->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			longitude = (map[i][j]->x_origin / param->x_max) * convert_angle(360) - convert_angle(180);
			latitude = convert_angle(90) - (map[i][j]->y_origin / param->y_max) * convert_angle(180);
			map[i][j]->x = cos(latitude) * cos (longitude);
			map[i][j]->y = cos (latitude) * sin (longitude);
			map[i][j]->z = sin(latitude);
			//map[i][j]->z = fmin(map[i][j]->z, 0.999999);
			scale_matrix(param, scale);
			test(scale, map[i][j]);
			center_win_matrix(center);
			test(center, map[i][j]);
			stereo_matrix(projection);
			test(projection, map[i][j]);
		}
	}
	apply_transform(param, param->transformation);
	/* multiply_matrix(scale, projection, matrix);
	multiply_matrix(matrix, center, tmp);
	m_to_point(param, matrix); */
}

/* static void	stereo_matrix(double matrix[4][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = -1;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	stereographic(t_mlx *param)
{
	double	longitude;
	double	latitude;
	double	center[4][4];
	double	projection[4][4];
	double	matrix[4][4];
	t_point	***map;
	int		i;
	int		j;

	map = param->map;
	i = -1;
	map = param->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			longitude = (map[i][j]->x_origin / param->x_max) * convert_angle(360) - convert_angle(180);
			latitude = convert_angle(90) - (map[i][j]->y_origin / param->y_max) * convert_angle(180);
			map[i][j]->x *= cos(latitude) * cos (longitude);
			map[i][j]->y *= cos (latitude) * sin (longitude);
			map[i][j]->z *= sin(latitude);
		}
	}
	center_win_matrix(center);
	stereo_matrix(projection);
	multiply_matrix(center, projection, matrix);
	m_to_point(param, matrix);
} */

/* static void	stereo_matrix(double matrix[4][4], t_point *point)
{
	matrix[0][0] = point->x / (1 - point->z);
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = point->y / (1 - point->z);
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = -1;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	test(double matrix[4][4], t_point *point)
{
	double	xyz[3];
	double	w;

	w  = matrix[3][0] * point->x + matrix[3][1]
		* point->y + matrix[3][2] * point->z + matrix[3][3];
	xyz[0] = matrix[0][0] * point->x + matrix[0][1] * point->y
		+ matrix[0][2] * point->z + matrix[0][3] / w;
	xyz[1] = matrix[1][0] * point->x + matrix[1][1] * point->y
		+ matrix[1][2] * point->z + matrix[1][3] / w;
	xyz[2] = matrix[2][0] * point->x + matrix[2][1] * point->y
		+ matrix[2][2] * point->z + matrix[2][3] / w;
	point->x = xyz[0];
	point->y = xyz[1];
	point->z = xyz[2];
}

void	stereographic(t_mlx *param)
{
	double	longitude;
	double	latitude;
	double	scale[4][4];
	double	projection[4][4];
	double	center[4][4];
	t_point	***map;
	int		i;
	int		j;

	map = param->map;
	i = -1;
	map = param->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			//printf("x=%f,y=%f,z=%f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			longitude = (map[i][j]->x_origin / param->x_max) * convert_angle(360) - convert_angle(180);
			latitude = convert_angle(90) - (map[i][j]->y_origin / param->y_max) * convert_angle(180);
			printf("lon = %f, lat = %f\n", sin(latitude), cos(latitude));
			map[i][j]->x = cos(latitude) * cos (longitude);
			map[i][j]->y = cos (latitude) * sin (longitude);
			map[i][j]->z = sin(latitude);
			map[i][j]->z = fmin(map[i][j]->z, 0.999999);
			stereo_matrix(projection, map[i][j]);
			test(projection, map[i][j]);
			scale_matrix(param, scale);
			test(scale, map[i][j]);
			center_win_matrix(center);
			test(center, map[i][j]);
			//printf("x=%f,y=%f,z=%f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
		}
	}
	apply_transform(param, param->transformation);
} */