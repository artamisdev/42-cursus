/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:50 by tacampos          #+#    #+#             */
/*   Updated: 2024/12/08 18:45:01 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate(char **argv)
{
	if (check_width_map(argv[1]) == 1)
		return (ft_printf("This map is not rectangular!\n"));
	if (check_collectibles(argv[1]) == 1)
		return (ft_printf("This map doesn't have enough collectibles!\n"));
	if (check_player_map(argv[1]) == 1)
		return (ft_printf("The amount of players must be 1.\n"));   
    if (check_exit_map(argv[1]) == 1)
		return (ft_printf("The amount of exits must be 1.\n"));
	if (check_the_side_walls(argv[1]) != 0)
        return(ft_printf("The walls of this map are not valid!\n"));
	if (check_lower_wall(argv[1]) == 1)
		return(ft_printf("The walls of this map are not valid!\n"));
	if (check_upper_wall(argv[1]) == 1)
		return(ft_printf("The walls of this map are not valid!\n"));
	if (check_valid_char_map(argv[1]) == 1)
        return (ft_printf("This is a invalid map!\n"));
	return (EXIT_SUCCESS);      
}

void free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game->map);
	exit(0);
	return (EXIT_SUCCESS);
}
void	move(t_game *game, int keycode)
{	
	if (keycode == A || keycode == A_ARROW)
	{
		if (game->map[game->y][game->x - 1] != WALL)
			game->x--;
	}
	if (keycode == D || keycode == D_ARROW)
	{
		if (game->map[game->y][game->x + 1] != WALL)
			game->x++;
	}
	if (keycode == W || keycode == W_ARROW)
	{
		if (game->map[game->y - 1][game->x] != WALL)
			game->y--;
	}
	if (keycode == S || keycode == S_ARROW)
	{
		if (game->map[game->y + 1][game->x] != WALL)
			game->y++;
	}		
}

int on_keypress(int keycode, t_game *game)
{
	(void)game;
	if (keycode == ESC)
		return(on_destroy(game));
	counter_steps(game,keycode);
	move(game, keycode);
	deploy_p(game);
	
	if (game->map[game->y][game->x] == COLLECTIBLE)
	{
		game->map[game->y][game->x] = GROUND;
		game->count_collectible--;
		ft_printf("Collectibles Left: %d\n", game->count_collectible);
	}
	if (game->map[game->y][game->x] == EXIT)
	{
		if (game->count_collectible == 0)
			return(on_destroy(game));
	}
	// ft_printf("X = %d\n Y = %d\n", game->x, game->y);
	// ft_printf("Pressed key: %d\n", keycode);
	ft_printf("Steps: %d\n", game->count_steps);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	size_t	line_count;
	char	*line;
	char	*confirm;
	int		check;
	t_game	game;

	if (argc != 2)
		return (ft_printf("Bad list of arguments\n"));
	confirm = ft_strrchr(argv[1], '.');
	check = ft_strncmp(confirm, ".ber", ft_strlen(confirm));
	if (check != 0)
		return (ft_printf("Bad file extension (%s)\n", confirm));
	
    if (validate(argv))
		return(EXIT_FAILURE);
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Could not open file!\n"));
	
	//ft_printf("passou todos checks\n");
	
	line_count = count_lines(argv[1]);
	//ft_printf("line count; %d\n\n", line_count);
	game.map = ft_calloc(line_count + 1, sizeof(char *));
	if (!game.map)
		return (ft_printf("Failed allocating memory for map!\n"));
	i = 0;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		game.map[i] = line;
		//ft_printf("%s", game.map[i]);
		line = get_next_line(fd);
		i++;
	}
	close(fd);

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (ft_printf("Failed initializing MLX!\n")); // liberar todo antes de salir <(nwn)>
	game.win_ptr = mlx_new_window(game.mlx_ptr, ft_strlen(game.map[0]) * PIXEL_SIZE, line_count * PIXEL_SIZE, "The Dino Dino"); // fazer a janela se adaptar ao tamanho do mapa
	
	if (!game.win_ptr)
		return (free(game.mlx_ptr), ft_printf("Failed opening window!\n")); //  liberar todo antes de salir <(nwn)> (map)

	if (load_images(&game))
		return (EXIT_FAILURE); //  liberar todo antes de salir <(nwn)> (map)

	count_collectibles(&game);
	game.count_steps = 0; 
	// Deploy background
	deploy_background(&game);
	p_reposition(&game);	 
	//liberar todo antes de salir <(nwn)> (map)

	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	mlx_loop(game.mlx_ptr);
	
	return (EXIT_SUCCESS);
}
