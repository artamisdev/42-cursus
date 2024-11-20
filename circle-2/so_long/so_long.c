/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:50 by tacampos          #+#    #+#             */
/*   Updated: 2024/11/20 14:39:28 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file_name)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// ft_printf("\n%d",line_count);
	return (line_count);
}

int	check_width_map(char *file_name)
{
	int		fd;
	char	*read_line;
	size_t	width;
	size_t	len;
	int		error;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	error = 0;
	read_line = get_next_line(fd);
	width = ft_strlen(read_line);
	if (ft_strchr(read_line, '\n') != NULL)
		width--;
	while (read_line != NULL)
	{
		len = ft_strlen(read_line);
		if (ft_strchr(read_line, '\n') != NULL)
			len--;
		if (len != width)
			error = 1;
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (error);
}

int	check_valid_char_map(char *file_name)
{
	int		fd;
	int		error;
	size_t	j;
	char	*str;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	error = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		j = 0;
		while (j < ft_strlen(str))
		{
			if (str[j] != '1' && str[j] != '0' && str[j] != 'E' && str[j] != 'C'
				&& str[j] != 'P' && str[j] != '\n')
				error = 1;
			j++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (error);
}

int	check_exit_map(char *file_name)
{
	int		fd;
	size_t	i;
	int		counter_e;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
	counter_e = 0;
	while (read_line != NULL)
	{
		i = 0;
		while (i < ft_strlen(read_line))
		{
			if (read_line[i] == 'E')
				++counter_e;
			i++;
		}
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (counter_e != 1 );
}
int	check_player_map(char *file_name)
{
	int		fd;
	size_t	i;
    int		counter_p;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
    counter_p = 0;
	while (read_line != NULL)
	{
		i = 0;
		while (i < ft_strlen(read_line))
		{
            if (read_line[i] == 'P')
				++counter_p;
			i++;
		}
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (counter_p != 1);
}
int	check_collectibles(char *file_name)
{
	int		fd;
	size_t	i;
    int		counter;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
    counter = 0;
	while (read_line != NULL)
	{
		i = 0;
		while (i < ft_strlen(read_line))
		{
            if (read_line[i] == 'C')
				counter++;
			i++;
		}
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (counter < 1);
}

int check_the_side_walls(char *file_name)
{
    int		fd;
	char	*read_line;
    int     error;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
    read_line = get_next_line(fd);
    error = 0;
    while(read_line != NULL)
    {
        if (read_line[ft_strlen(read_line) - 1] == '\n')
            read_line[ft_strlen(read_line) - 1] = '\0';
        if (read_line[0] != '1')
            error++;
        if (read_line[ft_strlen(read_line) - 1] != '1')
            error++;
        free(read_line);
        read_line = get_next_line(fd);
    };
    close(fd);
    return(error);
};

int check_char_one(char *read_line)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	if (read_line[ft_strlen(read_line) - 1] == '\n')
		read_line[ft_strlen(read_line) - 1] = '\0';
	while (read_line[i])
	{
		if (read_line[i] != '1')
			error++;
		i++;
	}
	
	return(error);
}

int check_lower_wall(char *file_name)

{
	int		fd;
	int		error;
	char	*next_line;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	error = 0;
	read_line = get_next_line(fd);
	while (read_line != NULL)
	{
		next_line = get_next_line(fd);
		if (next_line != NULL)
		{
			free(read_line);
			read_line = next_line;
			continue ;
		}
		error = check_char_one(read_line);
		free(read_line);
		read_line = NULL;
	}
	close(fd);
	return (error);	
}

int check_upper_wall(char *file_name)
{
	int		fd;
	int		error;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
	error = check_char_one(read_line);
	free(read_line);
	close(fd);
	return(error);
}

int validate(char **argv)
{
	if (check_width_map(argv[1]) == 1)
		return (ft_printf("This map is not rectangular!\n"));
	//ft_printf("passou check width\n");

	if (check_collectibles(argv[1]) == 1)
		return (ft_printf("This map doesn't have enough collectibles!\n"));
	//ft_printf("passou check collectibles\n");
        
	if (check_player_map(argv[1]) == 1)
		return (ft_printf("The amount of players must be 1.\n"));
	//ft_printf("passou check player\n");
        
    if (check_exit_map(argv[1]) == 1)
		return (ft_printf("The amount of exits must be 1.\n"));
	//ft_printf("passou check exits\n");
	
	if (check_the_side_walls(argv[1]) != 0)
        return(ft_printf("The walls of this map are not valid!\n"));
	//ft_printf("passou check side walls\n");
		
	if (check_lower_wall(argv[1]) == 1)
		return(ft_printf("The walls of this map are not valid!\n"));
	//ft_printf("passou check lower wall\n");
	
	if (check_upper_wall(argv[1]) == 1)
		return(ft_printf("The walls of this map are not valid!\n"));
	//ft_printf("passou check upper wall\n");
        
	if (check_valid_char_map(argv[1]) == 1)
        return (ft_printf("This is a invalid map!\n"));
	//ft_printf("passou valid chars\n");
	
	return (EXIT_SUCCESS);      
}


int on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (EXIT_SUCCESS);
}

int on_keypress(int keycode, t_game *game)
{
	(void)game;
	if (keycode == ESC)
		return(on_destroy(game));
	//if (keycode == A)
	//if (keycode == S)
	//if (keycode == W)
	//if (keycode == D)
	//if (keycode == A_ARROW)
	//if (keycode == S_ARROW)
	//if (keycode == W_ARROW)
	//if (keycode == D_ARROW)
		
	ft_printf("Pressed key: %d\n", keycode);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	size_t	line_count;
	char	*line;
	char	**map;
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
	ft_printf("line count; %d\n\n", line_count);
	map = ft_calloc(line_count + 1, sizeof(char *));
	if (!map)
		return (ft_printf("Failed allocating memory for map!\n"));
	i = 0;

	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		map[i] = line;
		ft_printf("%s", map[i]);
		i++;
	}
	close(fd);

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (ft_printf("Failed initializing MLX!\n")); // liberar todo antes de salir <(nwn)>
	game.win_ptr = mlx_new_window(game.mlx_ptr, 890, 380, "The Dino Dino"); // fazer a janela se adaptar ao tamanho do mapa
	
	if (!game.win_ptr)
		return (free(game.mlx_ptr), ft_printf("Failed opening window!\n")); //  liberar todo antes de salir <(nwn)> (map)

	// Load images
	t_img img;

	if (load_images(&game, &img))
		return (EXIT_FAILURE); //  liberar todo antes de salir <(nwn)> (map)
		

	// Deploy background
	if (deploy_background(&game, &img, map))
		return (EXIT_FAILURE); //  liberar todo antes de salir <(nwn)> (map)

	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
