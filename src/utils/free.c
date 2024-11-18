#include "fdf.h"

void	free_ptr(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free_ptr(&tab[i++]);
	}
}

void test_free(t_transform **transform)
{
	if (transform && *transform)
	{
		free(*transform);
		*transform = NULL;
	}
	*transform = NULL;
}

void free_special(t_mlx **param)
{
	if (param && *param)
	{
		free(*param);
		*param = NULL;
	}
	*param = NULL;
}

void	free_window(t_mlx **param)
{
	t_mlx *test;

	test = *param;

		map_clear(&test->map);
		mlx_destroy_window(test->mlx_ptr, test->win_ptr);
		if (test->transformation)
			test_free(&test->transformation);
		free_special(param);
		param = NULL;
		exit(0);
}