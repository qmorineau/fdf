#include "fdf.h"

void draw_point(t_mlx *param, t_point ***map)
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
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x + 1, (tmp[i][j]->y) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x + 2, (tmp[i][j]->y) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x - 1, (tmp[i][j]->y) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x - 2, (tmp[i][j]->y) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y + 1) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y + 2) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y - 1) - (tmp[i][j]->z), 0255000255);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y - 2) - (tmp[i][j]->z), 0255000255);
			//printf("here x = %f, y = %f, z = %f\n", tmp[i][j]->x, tmp[i][j]->y, tmp[i][j]->z);
			j++;
		}
		i++;
	}
}

void add_x(t_point *node)
{
	node->x -= 50;
}

void add_y(t_point *node)
{
	node->y -= 50;
}

void del_x(t_point *node)
{
	node->x += 50;
}

void del_y(t_point *node)
{
	node->y += 50;
}

void zoom_in(t_mlx *param)
{
	param->scale -= 5;
}


void draw_line(t_mlx *param, t_point *a, t_point *b)
{
	int i;

	i = 1;
	if (a->x == b->x)
	{
		while (a->y + i != b->y)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, a->x, a->y + i, 0255000255);
			i++;
		}
	}
	else
	{
		while (a->x + i != b->x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, a->x + i, a->y, 0255000255);
			i++;
		}
	}
}

void join_point(t_mlx *param)
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
				draw_line(param, param->map[y][x], param->map[y + 1][x]);
			if (param->map[y][x + 1])
				draw_line(param, param->map[y][x], param->map[y][x + 1]);
			x++;
		}
		y++;
	}

}

void	test2(t_point ***map, void (*f)(t_point *, double x, double y, double z))
{
	int		i;
	int		j;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{

			f(map[i][j], map[i][j]->x, map[i][j]->y, map[i][j]->z);
			j++;
		}
		i++;
	}
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
	else if (keycode == X)
		rotate_x(param, 10);
	else if (keycode == Y)
		rotate_y(param, 10);
	else if (keycode == Z)
		rotate_z(param, 10);
	else if (keycode == C)
	{
		decentered_win_obj(param);
		centered_win_obj(param);
	}
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_point(param, param->map);
	//join_point(param);
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
	all->scale = 80;
	all->center_x = 0;
	all->center_y = 0;
	if (!parsing(argv, all))
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		return(free(all), 0);
	}
	//orthographic(all);
	scaling(all);
	centered_win_obj(all);
	draw_point(all, all->map);
	//join_point(all);
	ft_printf("y\n");
	mlx_key_hook(all->win_ptr, handle_keypress, all);
	mlx_loop(all->mlx_ptr);
}
