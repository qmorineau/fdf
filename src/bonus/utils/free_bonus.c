/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:44 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/04 12:00:58 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_ptr(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_tab(char ***tab)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *tab;
	while (tmp[i])
	{
		free_ptr(&tmp[i++]);
	}
	free(*tab);
	*tab = NULL;
}

void	free_wrong_parsing(t_mlx *param)
{
	map_clear(&param->map);
	if (param->transformation)
		free(param->transformation);
	param->transformation = NULL;
	free(param);
	param = NULL;
	exit(0);
}

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free_ptr(&line);
		line = get_next_line(fd);
	}
}

int	free_if_not_row(char **line, char ***tab)
{
	free_ptr(line);
	free_tab(tab);
	malloc_error();
	return (0);
}
