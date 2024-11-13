#include "fdf.h"

/* void draw_point(t_mlx *param, t_point ***map)
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
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x + 1, (tmp[i][j]->y) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x + 2, (tmp[i][j]->y) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x - 1, (tmp[i][j]->y) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x - 2, (tmp[i][j]->y) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y + 1) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y + 2) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y - 1) - (tmp[i][j]->z), 0xFFFFFF);
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, tmp[i][j]->x, (tmp[i][j]->y - 2) - (tmp[i][j]->z), 0xFFFFFF);
			printf("here x = %f, y = %f, z = %f\n", tmp[i][j]->x, tmp[i][j]->y, tmp[i][j]->z);
			j++;
		}
		i++;
	}
} */

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

void ortho_point(t_mlx *param, double x, double y, double z)
{
	double matrix[4][4];
	double 	new_x;
	double	new_y;

	ortho_matrix(matrix);
	new_x = (matrix[0][0] * x) + (matrix[0][1]
		* y) + (matrix[0][2] * z) + matrix[0][3];
	new_y = (matrix[1][0] * x) + (matrix[1][1]
		* y) + (matrix[1][2] * z) + matrix[1][3];
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, new_x, new_y, 0xFFFFFF);
	/* mlx_pixel_put(param->mlx_ptr, param->win_ptr, x * param->scale, y * param->scale, 0xFFFFFF); */
}

/* void join_point(t_mlx *param)
{
	int x;
	int y;

	x = 0;
	y = 0;
	//printf("1\n");
	while (param->map[y])
	{
		//printf("2\n");
		x = 0;
		while (param->map[y][x])
		{
			//printf("3\n");
			if (param->map[y + 1])
				draw_line(param, param->map[y][x], param->map[y + 1][x]);
			if (param->map[y][x + 1])
				draw_line(param, param->map[y][x], param->map[y][x + 1]);
			x++;
		}
		y++;
	}

} */

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

/* int key_press(int keycode, t_mlx *param)
{
	printf("keypress\n");
    if (keycode == ESC)
	{
		map_clear(&param->map);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param);
		exit(0);
	}
	else
		param->key_press = keycode;
    return (0);
}

int	key_release(int keycode, t_mlx *param)
{
	printf("keyrelease\n");
	if (keycode == param->key_press)
		param->key_press = 0;
	return (0);
} */

/* int loop_hook(t_mlx *param)
{
	printf("key = %d\n", param->key_press);
	if (param->key_press == UP)
		map_iter(param->map, add_y);
	else if (param->key_press == DOWN)
		map_iter(param->map, del_y);
	else if (param->key_press == LEFT)
		map_iter(param->map, add_x);
	else if (param->key_press == RIGHT)
		map_iter(param->map, del_x);
	else if (param->key_press == X)
		rotate_x(param, 10);
	else if (param->key_press == Y)
		rotate_y(param, 10);
	else if (param->key_press == Z)
		rotate_z(param, 10);
	else if (param->key_press == C)
		centered_obj(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	orthographic(param);
	return (0);
} */

void reset(t_point *node)
{
	node->x = node->x_origin;
	node->y = node->y_origin;
	node->z = node->z_origin;
}

void apply_transform(t_mlx *param, t_transform *data)
{
	int i;

	i = 0;
	while (i < data->rx % 36)
		i++;
	rotate_x(param, 10 * i);
	i = 0;
	while (i < data->ry % 36)
		i++;
	rotate_y(param, 10 * i);
	i = 0;
	while (i < data->rz % 36)
		i++;
	rotate_z(param, 10 * i);
}

int handle_keypress(int keycode, t_mlx *param)
{
    printf("Key pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		map_clear(&param->map);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param->transformation);
		free(param);
		exit(0);
	}
	/* else if (keycode == UP)
		map_iter(param->map, add_y);
	else if (keycode == DOWN)
		map_iter(param->map, del_y);
	else if (keycode == LEFT)
		map_iter(param->map, add_x);
	else if (keycode == RIGHT)
		map_iter(param->map, del_x); */
	else if (keycode == X)
	{
		//rotate_x(param, 10);
		param->transformation->rx++;
	}
	else if (keycode == Y)
	{
		//rotate_y(param, 10);
		param->transformation->ry++;
	}
	else if (keycode == Z)
	{
		//rotate_z(param, 10);
		param->transformation->rx++;
	}
	else if (keycode == C)
		centered_obj(param);
	printf("oui\n");
	map_iter(param->map, reset);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	centered_obj(param);
	scaling(param, 0);
	rotate_x(param, 45);
	rotate_y(param, 45);
	centered_win(param);
	apply_transform(param, param->transformation);
	orthographic(param);
	map_iter(param->map, reset);
    return (0);
}

int init_param_transform(t_mlx *param)
{
	param->transformation = malloc(sizeof(t_transform));
	if (!param->transformation)
		return (0);
	param->transformation->rx = 0;
	param->transformation->ry = 0;
	param->transformation->rz = 0;
	return (1);
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
	all->scale = 15000;
	all->center_x = 0;
	all->center_y = 0;
	if (!parsing(argv, all))
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		return(free(all), 0);
	}
	if (!init_param_transform(all))
		return (free(all), 0);
	centered_obj(all);
	scaling(all, 0);
	rotate_x(all, 45);
	rotate_y(all, 45);
	centered_win(all);
	orthographic(all);
	printf("oui\n");
	mlx_key_hook(all->win_ptr, handle_keypress, all);
	mlx_loop(all->mlx_ptr);
}


/* int main(int argc, char *argv[])
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
	all->scale = 10000;
	all->center_x = 0;
	all->center_y = 0;
	all->key_press = 0;
	if (!parsing(argv, all))
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		return(free(all), 0);
	}
	centered_obj(all);
	scaling(all, 0);
	rotate_x(all, 30);
	rotate_y(all, 30);
	centered_win(all);
	orthographic(all);

	printf("1\n");
	mlx_hook(all->win_ptr, KEY_PRESS, 0, key_press, all);
	printf("2\n"); */
	//mlx_hook(all->win_ptr, KEY_RELEASE, 0, key_release, all);
	/* printf("3\n"); */
	/* printf("4\n");
	mlx_loop_hook(all->mlx_ptr, loop_hook, all); 
	mlx_key_hook(all->win_ptr, handle_key, all);
	mlx_loop(all->mlx_ptr);
}
 */