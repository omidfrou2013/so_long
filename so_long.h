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
	void	*player_img;
	void	*wall_img;
	void	*banana_img;
	void	*exit_img;
	char	**map;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
}	t_game;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_img;

//parsing
char	**read_map(char *file);
static void	check_characters(char **map, int row, int *p, int *e, int *c);
void	check_map(char **map);
static void	flood_fill_util(char **map, int x, int y, int rows, int cols);

//exit
void	free_map(char **map, int rows);
void	clean_exit(char **map, int rows, void *mlx, void *win);
void	error_exit(char *message);
void	ft_putendl_fd(char *s, int fd);
static void	check_walls(char **map, int rows, int cols);

//moves
static void	move_player(char **map, int *player_x, int *player_y, char direction);
static void	update_map(char **map, int player_x, int player_y);
void	handle_player_move(char **map, int *player_x, int *player_y, char direction, int *moves);
void	ft_putnbr_fd(int n, int fd);

//win
static int	check_victory(char **map, int player_x, int player_y);
static int	check_loss(char **map, int player_x, int player_y);
void	handle_game_status(char **map, int player_x, int player_y, int *moves);
void	ft_putendl_fd(char *s, int fd);

//render
void	render_tile(t_game *game, void *img, int x, int y);
void	render_graphic(t_game *game);
void	load_images(t_game *game);

//main
static int	game_loop(t_game *game);
static void	init_game(t_game *game, char *map_file);

#endif