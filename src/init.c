#include "fdf.h"

static int init_param_transform(t_mlx *param)
{
	param->transformation = malloc(sizeof(t_transform));
	if (!param->transformation)
	{
		malloc_error();
		return (0);
	}
	param->transformation->rx = 0;
	param->transformation->ry = 0;
	param->transformation->rz = 0;
	param->transformation->tx = 0;
	param->transformation->ty = 0;
	param->transformation->tz = 0;
	return (1);
}

void	destroying(t_mlx *param)
{
	map_clear(&param->map);
	if (param->transformation)
		free(param->transformation);
	param->transformation = NULL;
	free(param->mlx_ptr);
	free(param);
	param = NULL;
	exit(0);
}

void init_z_min_max(t_mlx *param)
{
	int i = -1;
	int j = -1;

	param->z_min = param->map[0][0]->z_origin;
	param->z_max = param->map[0][0]->z_origin;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			if (param->z_min > param->map[i][j]->z_origin)
				param->z_min = param->map[i][j]->z_origin;
			if (param->z_max < param->map[i][j]->z_origin)
				param->z_max = param->map[i][j]->z_origin;
		}
	}
}

t_mlx *init_window(char *argv[])
{
	t_mlx	*param;

	param = malloc(sizeof(t_mlx));
	if (!param)
	{
		malloc_error();
		exit(0);
	}
	param->map = NULL;
	param->projection = ISOMETRIC;
	param->color = STANDARD;
	param->transformation = NULL;
	if (!parsing(argv, param))
		destroying(param);
	if (!init_param_transform(param))
		destroying(param);
	init_z_min_max(param);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fdf");
	return (param);
}
