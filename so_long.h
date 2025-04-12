#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_w;
	int		map_h;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
}	t_game;

//parsing
char	**read_map(char *file);
static void	check_walls(char **map, int rows, int cols);
static void	check_characters(char **map, int row, int *p, int *e, int *c);
void	check_map(char **map);

//main
int	game_loop(t_game *game);
void	init_game(t_game *game, char *map_file);

#endif