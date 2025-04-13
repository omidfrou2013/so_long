#include "so_long.h"

char	**read_map(char *file)
{
	int		fd;
	char	*line;
	char	*map_str;
	char	*tmp;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("cannot open map file");
	map_str = ft_strdup("");
	while ((line = get_next_line(fd)))
	{
		tmp = ft_strjoin(map_str, line);
		free(map_str);
		map_str = tmp;
		free(line);
	}
	close(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

static void	check_characters(char **map, int row, int *p, int *e, int *c)
{
	int	i;

	i = 0;
	while (map[row][i])
	{
		if (map[row][i] == 'P') (*p)++;
		else if (map[row][i] == 'E') (*e)++;
		else if (map[row][i] == 'C') (*c)++;
		else if (map[row][i] != '1' && map[row][i] != '0')
			error_exit("invalid character in map");
		i++;
	}
}

void	check_map(char **map)
{
	int	row;
	int	col;
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	row = 0;
	col = ft_strlen(map[0]);
	while (map[row])
	{
		if ((int)ft_strlen(map[row]) != col)
			error_exit("map is not rectangular");
		check_characters(map, row, &p, &e, &c);
		row++;
	}
	if (p != 1 || e == 0 || c == 0)
		error_exit("map must have 1 player, at least 1 exit and 1 collectible");
	check_walls(map, row, col);
}

static void	flood_fill_util(char **map, int x, int y, int rows, int cols)
{
	if (x < 0 || x >= rows || y < 0 || y >= cols)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';  // 'V' marks visited spots
	flood_fill_util(map, x + 1, y, rows, cols);
	flood_fill_util(map, x - 1, y, rows, cols);
	flood_fill_util(map, x, y + 1, rows, cols);
	flood_fill_util(map, x, y - 1, rows, cols);
}

void	flood_fill(char **map, int rows, int cols, int start_x, int start_y)
{
	if (map[start_x][start_y] == '1')
		error_exit("starting point is blocked");
	flood_fill_util(map, start_x, start_y, rows, cols);
}