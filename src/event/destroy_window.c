#include "fdf.h"

int	destroy_window(t_mlx **param)
{
	t_mlx *ptr;

	ptr = *param;
	mlx_destroy_image(ptr->mlx_ptr, ptr->img);
	map_clear(&ptr->map);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	if (ptr->transformation)
		free(ptr->transformation);
	ptr->transformation = NULL;
	free(param);
	param = NULL;
	exit(0);
	return (0);
}
