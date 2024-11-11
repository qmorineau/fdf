#include "fdf.h"

void create_square(t_mlx *param, t_point ***map)
{
	t_point ***tmp;
	int		i;
	int		j;

	i = 0;
	tmp = map;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x * param->zoom, (tmp[i][j]->y * param->zoom) - (tmp[i][j]->z * 10), 0255000255);
			j++;
		}
		i++;
	}
}

void add_x(t_point *node)
{
	node->x += 1;
}

void add_y(t_point *node)
{
	node->y += 1;
}

void del_x(t_point *node)
{
	node->x -= 1;
}

void del_y(t_point *node)
{
	node->y -= 1;
}

void zoom_in(t_mlx *param)
{
	param->zoom -= 5;
}

void zoom_out(t_mlx *param)
{
	param->zoom += 5;
}

int handle_keypress(int keycode, t_mlx *param)
{
    printf("Key pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		map_clear(&param->map);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param);
		exit(0);
	}
	else if (keycode == UP)
		map_iter(param->map, add_y);
	else if (keycode == DOWN)
		map_iter(param->map, del_y);
	else if (keycode == LEFT)
		map_iter(param->map, add_x);
	else if (keycode == RIGHT)
		map_iter(param->map, del_x);
	else if (keycode == 106)
		zoom_out(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
		create_square(param, param->map);
    return (0);
}

int main(int argc, char *argv[])
{
	t_mlx *all;

	(void) argc;
	all = malloc(sizeof(t_mlx));
	if (!all)
		return (0);
	all->map = NULL;
	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, WIDTH, HEIGHT, "fdf");
	if (!all->win_ptr)
		return (free(all), 0);
	all->zoom = 50;
	if (!parsing(argv, all))
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		return(free(all), 0);
	}
	create_square(all, all->map);
	mlx_key_hook(all->win_ptr, handle_keypress, all);
	mlx_loop(all->mlx_ptr);
}