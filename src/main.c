/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:51 by qmorinea          #+#    #+#             */
/*   Updated: 2024/11/22 17:47:07 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print(t_point *node)
{
	printf("x=%f, y=%f, z=%f\n", node->x, node->y, node->z);
}

void	test_error(void)
{
	int	i;

	i = -1;
	while (++i < 100)
	{
		ft_putstr_fd(strerror(i), 2);
		ft_printf("\n i = %d\n", i);
	}
}

int main(int argc, char *argv[])
{
	t_mlx	*param;

	//test_error();
	if (argc != 2)
	{
		ft_putstr_fd(strerror(7), 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	if (!is_fdf_file(argv[1]))
		return (0);
	param = init_window(argv);
	if (!param)
		return (0);
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->size_line, &param->endians);

	centered_obj(param);
	init_scaling(param);
	do_projection(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);

	mlx_mouse_hook(param->win_ptr, handle_mouse, param);
	mlx_hook(param->win_ptr, 3, 2, handle_keyrelease, param);
	mlx_hook(param->win_ptr, 2, 1, handle_keypress, param);

	mlx_hook(param->win_ptr, 17, 0, destroy_window, param);
	mlx_loop_hook(param->mlx_ptr, render_frame, param);
	mlx_loop(param->mlx_ptr);

	mlx_destroy_image(param->mlx_ptr, param->img);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	return (0);
}
