#include "fdf.h"

static int init_param_transform(t_mlx *param)
{
	param->transformation = malloc(sizeof(t_transform));
	if (!param->transformation)
		return (0);
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
		exit(0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(param);
		exit(0);
	}
	param->map = NULL;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fdf");
	param->projection = ORTHOGRAPHIC;
	param->color = STANDARD;
	param->transformation = NULL;
	if (!parsing(argv, param))
		free_window(&param);
	if (!init_param_transform(param))
		free_window(&param);
	return (param);
}
