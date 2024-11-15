#include "fdf.h"

static int add_line(t_mlx *param, char *line, int y)
{
	char	**tab;
	int		x;
	t_point **row;
	t_point *tmp;
	int		tab_len;

	tab = ft_split(line, ' ');
	if (!tab)
	{
		free_ptr(&line);
		return (0);
	}
	tab_len = 0;
	while (tab[tab_len])
		tab_len++;
	row = ft_calloc(tab_len + 1, sizeof(t_point *));
	x = 0;
	while (tab[x])
	{
		tmp = map_newpoint((double) x, (double)y, (double) ft_atoi(tab[x]));
		if (!tmp)
		{
			free_ptr(&line);
			return (0);
		}
		row[x] = tmp;
		x++;
	}
	param->x_max = (double) (x - 1);
	param->map[y] = row;
	free_tab(tab);
	free(tab);
	tab = NULL;
	free_ptr(&line);
	return (1);
}

t_point ***init_map(t_point ***new, t_point ****old, int rows)
{
	int i;
	t_point ***tmp;

	i = 0;
	if (!old)
		return (new);
	tmp = *old;
	while (i < rows)
	{
		new[i] = tmp[i];
		i++;
	}
	free(*old);
	return (new);
}

int parsing(char *argv[], t_mlx *all)
{
	t_point	***tmp;
	int		fd;
	char	*line;
	int		y;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		tmp = ft_calloc(y + 2, sizeof(t_point **));
		if (!tmp)
			return (0);
		all->map = init_map(tmp, &all->map, y);
		if (!add_line(all, line, y))
			return (0);
		line = get_next_line(fd);
		y++;
	}
	all->y_max = (double) (y - 1);
	return (1);
}
