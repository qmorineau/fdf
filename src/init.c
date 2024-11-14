#include "fdf.h"

static int init_param_transform(t_mlx *param)
{
	param->transformation = malloc(sizeof(t_transform));
	if (!param->transformation)
		return (0);
	param->transformation->rx = 0;
	param->transformation->ry = 0;
	param->transformation->rz = 0;
	return (1);
}

t_mlx *init_window(char *argv[])
{
	t_mlx *param;

	param = malloc(sizeof(t_mlx));
	if (!param)
		return (NULL);
	param->map = NULL;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fdf");
	if (!param->win_ptr)
		return (free(param), NULL);
	param->scale = 10000;
	param->center_x = 0;
	param->center_y = 0;
	param->projection = ORTHOGRAPHIC;
	if (!parsing(argv, param))
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		return(free(param), NULL);
	}
	if (!init_param_transform(param))
		return (free(param), NULL);
	return (param);
}
