/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fdf_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:00:00 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/04 12:01:55 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	is_fdf_file(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (!ft_strncmp(&argv[len - 4], ".fdf", 4))
		return (1);
	else
	{
		wrong_fd_error();
		return (0);
	}
}
