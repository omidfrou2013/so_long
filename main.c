#include "so_long.h"

static int	game_loop(t_game *game)
{
	handle_game_status(game->map, game->player_x,
		game->player_y, &game->moves);
	render_graphic(game);
	if (move_player(game))
		update_map(game);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	return (0);
}

static void	init_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_error("MLX init failed", game);
	game->map = load_map(map_file);
	if (!game->map)
		exit_with_error("Map load failed", game);
	load_images(game);
	game->player_x = 1;
	game->player_y = 1;
	game->moves = 0;
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, "So Long");
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./so_long <map_file>", 2);
		return (1);
	}
	init_game(&game, argv[1]);
	clean_exit(game.map, game.moves, NULL, NULL);
	return (0);
}
