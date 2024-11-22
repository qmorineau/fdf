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

t_mlx *init_window(char *argv[])
{
	t_mlx	*param;
	int		fd;

	param = malloc(sizeof(t_mlx));
	if (!param)
	{
		malloc_error();
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(param);
		exit(0);
	}
	param->map = NULL;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fdf");
	param->projection = ISOMETRIC;
	param->color = STANDARD;
	param->transformation = NULL;
	if (!parsing(argv, param))
		destroy_window(param);
	if (!init_param_transform(param))
		destroy_window(param);
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
	return (param);
}
