#include "fdf.h"

void malloc_error(void)
{
	ft_putstr_fd(strerror(12), 2);
	ft_putchar_fd('\n', 2);
}

void wrong_fd_error(void)
{
	ft_putstr_fd(strerror(9), 2);
	ft_putchar_fd('\n', 2);
}


