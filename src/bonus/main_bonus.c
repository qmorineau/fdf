/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmorinea < qmorinea@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:51 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/29 13:34:41 by qmorinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_mlx	*param;

	if (argc != 2)
		return (args_error(argc));
	if (!is_fdf_file(argv[1]))
		return (0);
	param = init_window(argv);
	if (!param)
		return (0);
	first_and_reset_render(param);
	mlx_key_hook(param->win_ptr, handle_keypress, param);
	mlx_mouse_hook(param->win_ptr, handle_mouse, param);
	mlx_hook(param->win_ptr, 17, 0, destroy_window, param);
	mlx_loop(param->mlx_ptr);
	destroy_window(param);
	return (0);
}
