/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:05 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/27 16:56:46 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mouse(int button, int x, int y, t_mlx *param)
{
	printf("button = %d\n", button);
	printf("x = %d, y = %d\n", x, y);
	if (button == SCROLL_U)
		scaling_percent(param, 110);
	else if (button == SCROLL_D)
		scaling_percent(param, 90);
	render_frame(param);
	return (0);
}
