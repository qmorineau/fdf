#include "fdf.h"

static int add_line(t_point ***map, char *line, int x)
{
	char	**tab;
	int		y;
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
	y = 0;
	while (tab[y])
	{
		tmp = map_newpoint(x + 1, y + 1, ft_atoi(tab[y]));
		if (!tmp)
		{
			free_ptr(&line);
			return (0);
		}
		row[y] = tmp;
		y++;
	}
	map[x - 1] = row;
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
	while (i + 1 < rows)
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
	int		x;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	x = 1;
	while (line)
	{
		tmp = ft_calloc(x + 1, sizeof(t_point **));
		if (!tmp)
			return (0);
		all->map = init_map(tmp, &all->map, x);
		if (!add_line(all->map, line, x))
			return (0);
		line = get_next_line(fd);
		x++;
	}
	return (1);
}
