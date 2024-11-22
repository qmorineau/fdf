/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:44 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/22 17:36:19 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	free(param->mlx_ptr);
	free(param);
	param = NULL;
	exit(0);
}
