/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lst_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:50 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 16:00:20 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	*map_newpoint(double x, double y, double z)
{
	t_point	*node;

	node = malloc(sizeof(t_point));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->z = z;
	node->x_origin = x;
	node->y_origin = y;
	node->z_origin = z;
	return (node);
}

void	map_clear(t_point ****map)
{
	t_point	***tmp;
	int		i;
	int		j;

	if (!(*map))
		return ;
	tmp = *map;
	i = -1;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			free(tmp[i][j]);
			tmp[i][j] = NULL;
		}
		free(tmp[i]);
		tmp[i] = NULL;
	}
	free(*map);
	*map = NULL;
}

void	map_iter(t_point ***map, void (*f)(t_point *))
{
	t_point	**row;
	int		i;
	int		j;

	i = 0;
	if (!map)
		return ;
	row = map[i++];
	while (row)
	{
		j = 0;
		while (row[j])
			f(row[j++]);
		row = map[i++];
	}
}
