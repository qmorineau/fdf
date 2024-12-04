/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:50:41 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/04 12:00:17 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	row_from_tab(char ***tab_add, t_point ***row_add, int *x, int y)
{
	t_point	**row;
	char	**tab;
	t_point	*tmp;

	row = *row_add;
	tab = *tab_add;
	while (tab[*x])
	{
		tmp = map_newpoint((double) *x, (double)y, (double) ft_atoi(tab[*x]));
		if (!tmp)
		{
			free(row);
			free_tab(tab_add);
			return (malloc_error(), 0);
		}
		row[*x] = tmp;
		(*x)++;
	}
	return (1);
}

static int	add_line(t_mlx *param, char *line, int y)
{
	char	**tab;
	int		x;
	t_point	**row;
	int		tab_len;

	tab = ft_split(line, 32);
	if (!tab)
		return (free_ptr(&line), 0);
	tab_len = 0;
	while (tab[tab_len])
		tab_len++;
	row = ft_calloc(tab_len + 1, sizeof(t_point *));
	if (!row)
		return (free_if_not_row(&line, &tab));
	x = 0;
	if (!row_from_tab(&tab, &row, &x, y))
		return (0);
	param->map[y] = row;
	free_tab(&tab);
	free_ptr(&line);
	if (y > 0 && param->x_max != x - 1)
		return (parsing_error(), 0);
	param->x_max = (double) x - 1;
	return (1);
}

static t_point	***init_map(t_point ***new, t_point ****old, int rows)
{
	int		i;
	t_point	***tmp;

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
	*old = NULL;
	return (new);
}

static int	create_row(t_mlx *param, char *line, int y)
{
	t_point	***tmp;

	tmp = ft_calloc(y + 2, sizeof(t_point **));
	if (!tmp)
	{
		malloc_error();
		return (0);
	}
	param->map = init_map(tmp, &param->map, y);
	if (!add_line(param, line, y))
		return (0);
	return (1);
}

int	parsing(char *argv[], t_mlx *param)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (args_error(1));
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		if (!create_row(param, line, y++))
		{
			map_clear(&param->map);
			free_gnl(fd);
			close(fd);
			return (0);
		}
		line = get_next_line(fd);
	}
	param->y_max = (double) y - 1;
	close(fd);
	return (1);
}
