#include "so_long.h"

static void	move_player(char **map, int *player_x, int *player_y, char direction)
{
	if (direction == 'U' && map[*player_x - 1][*player_y] != '1')
		(*player_x)--;
	else if (direction == 'D' && map[*player_x + 1][*player_y] != '1')
		(*player_x)++;
	else if (direction == 'L' && map[*player_x][*player_y - 1] != '1')
		(*player_y)--;
	else if (direction == 'R' && map[*player_x][*player_y + 1] != '1')
		(*player_y)++;
}

static void	update_map(char **map, int player_x, int player_y)
{
	map[player_x][player_y] = 'P';
}

void	handle_player_move(char **map, int *player_x, int *player_y, char direction, int *moves)
{
	move_player(map, player_x, player_y, direction);
	update_map(map, *player_x, *player_y);
	(*moves)++;
	ft_putnbr_fd(*moves, 1);
	write(1, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

