/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:44 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/22 15:48:48 by qmorinea         ###   ########.fr       */
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
