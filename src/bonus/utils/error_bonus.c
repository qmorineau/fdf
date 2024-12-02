/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:58 by qmorinea          #+#    #+#             */
/*   Updated: 2024/12/02 16:00:07 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	malloc_error(void)
{
	ft_putstr_fd(strerror(12), 2);
	ft_putchar_fd('\n', 2);
}

void	wrong_fd_error(void)
{
	ft_putstr_fd(strerror(9), 2);
	ft_putchar_fd('\n', 2);
}

void	parsing_error(void)
{
	ft_putstr_fd(strerror(5), 2);
	ft_putchar_fd('\n', 2);
}

int	args_error(int argc)
{
	if (argc < 2)
		ft_putstr_fd(strerror(22), 2);
	else
		ft_putstr_fd(strerror(7), 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
