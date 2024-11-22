/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:58 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/22 15:49:04 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
