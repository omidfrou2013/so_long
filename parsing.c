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

static void	check_walls(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			error_exit("top or bottom wall open");
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			error_exit("side walls open");
		i++;
	}
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
