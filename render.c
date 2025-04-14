#include "so_long.h"

void	render_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

void	render_graphic(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->img.floor, x, y);
			if (game->map[y][x] == '1')
				render_tile(game, game->img.wall, x, y);
			else if (game->map[y][x] == 'C')
				render_tile(game, game->img.collectible, x, y);
			else if (game->map[y][x] == 'E')
				render_tile(game, game->img.exit, x, y);
			else if (game->map[y][x] == 'P')
				render_tile(game, game->img.player, x, y);
			x++;
		}
		y++;
	}
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &w, &h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &w, &h);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &w, &h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &w, &h);
	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.exit || !game->img.collectible)
		exit_with_error("Failed to load images", game);
}
