#include "so_long.h"

static int	check_victory(char **map, int player_x, int player_y)
{
	if (map[player_x][player_y] == 'E')
	{
		ft_putendl_fd("Congratulations, you win!", 1);
		return (1);
	}
	return (0);
}

static int	check_loss(char **map, int player_x, int player_y)
{
	if (map[player_x][player_y] == 'X')
	{
		ft_putendl_fd("Game Over! You lost!", 1);
		return (1);
	}
	return (0);
}

void	handle_game_status(char **map, int player_x, int player_y, int *moves)
{
	if (check_victory(map, player_x, player_y))
	{
		clean_exit(map, *moves, NULL, NULL);
	}
	if (check_loss(map, player_x, player_y))
	{
		clean_exit(map, *moves, NULL, NULL);
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
