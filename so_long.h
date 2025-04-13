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
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	void	*player_img;
	void	*wall_img;
	void	*banana_img;
	void	*exit_img;
	char	**map;
	int		map_w;
	int		map_h;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
}	t_game;

//util1
char	**read_map(char *file);
static void	check_characters(char **map, int row, int *p, int *e, int *c);
void	check_map(char **map);
static void	flood_fill_util(char **map, int x, int y, int rows, int cols);

//util2
void	free_map(char **map, int rows);
void	clean_exit(char **map, int rows, void *mlx, void *win);
void	error_exit(char *message);
void	ft_putendl_fd(char *s, int fd);

//utilh
static void	check_walls(char **map, int rows, int cols);

//main
int	game_loop(t_game *game);
void	init_game(t_game *game, char *map_file);

#endif