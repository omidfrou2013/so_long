#include "so_long.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}


void	clean_exit(char **map, int rows, void *mlx, void *win)
{
	free_map(map, rows);
	if (mlx && win)
	{
		mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
	}
	exit(0);
}

void	error_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

