#include "fdf.h"

t_point	*map_newpoint(double x, double y, double z)
{
	t_point	*node;

	node = malloc(sizeof(t_point));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->z = z;
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
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
			free(tmp[i][j++]);
		free(tmp[i++]);
	}
	free(*map);
	*map = NULL;
}

void	map_iter(t_point ***map, void (*f)(t_point *))
{
	t_point **row;
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