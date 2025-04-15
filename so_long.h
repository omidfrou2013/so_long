#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <memory.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collect;
	int		moves;
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
void	check_map(char **map);

//exit
void	free_map(char **map, int rows);
void	clean_exit(char **map, int rows, void *mlx, void *win);
void	error_exit(char *message);
void	ft_putendl_fd(char *s, int fd);

//moves
void	handle_player_move(char **map, int *player_x, int *player_y, char direction, int *moves);
void	ft_putnbr_fd(int n, int fd);

//win
void	handle_game_status(char **map, int player_x, int player_y, int *moves);
void	ft_putendl_fd(char *s, int fd);

//render
void	render_tile(t_game *game, void *img, int x, int y);
void	render_graphic(t_game *game);
void	load_images(t_game *game);

#endif