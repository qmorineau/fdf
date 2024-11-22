#include "fdf.h"

void put_pixel_in_img(t_mlx *param, t_point p, int color)
{
	char *dst;

	(void) color;
 	dst = param->address + (int) p.y * param->size_line + (int) p.x * 4;
	*(unsigned int* )dst = color;
}

void draw_line(t_mlx *param)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		x = 0;
		while (param->map[y][x])
		{
			if (param->map[y + 1])
				draw_bresenham(param, param->map[y][x], param->map[y + 1][x]);
			if (param->map[y][x + 1])
				draw_bresenham(param, param->map[y][x], param->map[y][x + 1]);
			//put_pixel_in_img(param, *param->map[y][x], WHITE);
			x++;
		}
		y++;
	}
}

void print(t_point *node)
{
	printf("x=%f, y=%f, z=%f\n", node->x, node->y, node->z);
}

int render_frame(t_mlx *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img);
	param->img = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	param->address = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->size_line, &param->endians);
	map_iter(param->map, reset_xyz);
	centered_obj(param);
	scaling_percent(param, 100);
	apply_transform(param, param->transformation);
	do_projection(param);
	draw_line(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
	return (0);
}

int is_fdf_file(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (!ft_strncmp(&argv[len - 4], ".fdf", 4))
		return (1);
	else
	{
		ft_putstr_fd(strerror(9), 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
}

void test_error(void)
{
	int i;

	i = -1;
	while (++i < 100)
	{
		ft_putstr_fd(strerror(i), 2);
		ft_printf("\n i = %d\n", i);
	}
}

int main(int argc, char *argv[])
{
	t_mlx *param;

	test_error();
	if (argc != 2)
	{
		ft_putstr_fd(strerror(7), 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	if (!is_fdf_file(argv[1]))
		return (0);
	param = init_window(argv);
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
