#include "fdf.h"

int	destroy_window(t_mlx *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img);
	map_clear(&param->map);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_display(param->mlx_ptr);
	if (param->transformation)
		free(param->transformation);
	param->transformation = NULL;
	free(param->mlx_ptr);
	free(param);
	param = NULL;
	exit(0);
	return (0);
}
