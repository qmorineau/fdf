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
			printf("here x = %f, y = %f, z = %f\n", tmp[i][j]->x, tmp[i][j]->y, tmp[i][j]->z);
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

void zoom_out(t_mlx *param)
{
	double origin[4][4];
	double scale[4][4];
	double matrix[4][4];
	double tmp[4][4];
	t_point ***map;
	int i;
	int j;

	origin_matrix(param, origin);
	scale_matrix(scale, 2);
	multiply_matrix(origin, scale, tmp);
	origin_undo_matrix(param, origin);
	multiply_matrix(tmp, origin, matrix);
	map = param->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("centered x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			map[i][j]->x = (matrix[0][0] * map[i][j]->x) + (matrix[0][1] * map[i][j]->y) + (matrix[0][2] * map[i][j]->z) + matrix[0][3];
			map[i][j]->y = (matrix[1][0] * map[i][j]->x) + (matrix[1][1] * map[i][j]->y) + (matrix[1][2] * map[i][j]->z) + matrix[1][3];
			map[i][j]->z = (matrix[2][0] * map[i][j]->x) + (matrix[2][1] * map[i][j]->y) + (matrix[2][2] * map[i][j]->z) + matrix[2][3];
			printf("after x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			j++;
		}
		i++;
	}
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

void centered(t_mlx *param)
{
	/* double center[4][4];
	double translate[4][4]; */
	double matrix[4][4];
	t_point ***map;
	int i;
	int j;

	/* translation_matrix(translate); */
	center_matrix(matrix, param);
	/* multiply_matrix(translate, center, matrix); */
	map = param->map;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("centered x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			map[i][j]->x = (matrix[0][0] * map[i][j]->x) + (matrix[0][1] * map[i][j]->y) + (matrix[0][2] * map[i][j]->z) + matrix[0][3];
			map[i][j]->y = (matrix[1][0] * map[i][j]->x) + (matrix[1][1] * map[i][j]->y) + (matrix[1][2] * map[i][j]->z) + matrix[1][3];
			map[i][j]->z = (matrix[2][0] * map[i][j]->x) + (matrix[2][1] * map[i][j]->y) + (matrix[2][2] * map[i][j]->z) + matrix[2][3];
			printf("after x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			j++;
		}
		i++;
	}
}

void test(t_mlx *param)
{
	double matrix[4][4];
	double tmp[4][4];
	double rotate[4][4];
	double origin[4][4];
	t_point ***map;
	int i;
	int j;

	origin_matrix(param, origin);
	rx_matrix(rotate, 20);
	multiply_matrix(origin, rotate, tmp);
	origin_undo_matrix(param, origin);
	multiply_matrix(tmp, origin, matrix);
	map = param->map;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("before x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			map[i][j]->x = (matrix[0][0] * map[i][j]->x) + (matrix[0][1] * map[i][j]->y) + (matrix[0][2] * map[i][j]->z) + matrix[0][3];
			map[i][j]->y = (matrix[1][0] * map[i][j]->x) + (matrix[1][1] * map[i][j]->y) + (matrix[1][2] * map[i][j]->z) + matrix[1][3];
			map[i][j]->z = (matrix[2][0] * map[i][j]->x) + (matrix[2][1] * map[i][j]->y) + (matrix[2][2] * map[i][j]->z) + matrix[2][3];
			printf("after x = %f, y = %f, z = %f\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			j++;
		}
		i++;
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
	else if (keycode == 104)
		test(param);
	else if (keycode == 106)
		zoom_out(param);
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
	all->scale = 30;
	all->center_x = 0;
	all->center_y = 0;
	if (!parsing(argv, all))
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		return(free(all), 0);
	}
	centered(all);
	draw_point(all, all->map);
	//join_point(all);
	mlx_key_hook(all->win_ptr, handle_keypress, all);
	mlx_loop(all->mlx_ptr);
}
