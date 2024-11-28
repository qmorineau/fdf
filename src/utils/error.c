/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:58 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/29 00:32:24 by quentin          ###   ########.fr       */
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

void	parsing_error(void)
{
	ft_putstr_fd(strerror(5), 2);
	ft_putchar_fd('\n', 2);
}
