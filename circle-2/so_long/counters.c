/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:41:41 by tacampos          #+#    #+#             */
/*   Updated: 2024/12/08 18:41:44 by tacampos         ###   ########.fr       */
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
	return (line_count);
}
int count_collectibles(t_game *game)
{
	int i;
    int j;
	int	counter_c;

    i = 0;
	counter_c = 0;
    while (game->map && game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
			if (game->map[i][j] == COLLECTIBLE)
				counter_c++;
            j++;
        }
        i++;
    }
	game->count_collectible = counter_c;
	// ft_printf("counter_c: %d\n", counter_c);
	return(counter_c);
}

void	counter_steps(t_game *game, int keycode)
{	
	if (keycode == A || keycode == A_ARROW)
	{
		if (game->map[game->y][game->x - 1] != WALL)
			game->count_steps++;
	}
	if (keycode == D || keycode == D_ARROW)
	{
		if (game->map[game->y][game->x + 1] != WALL)
			game->count_steps++;
	}
	if (keycode == W || keycode == W_ARROW)
	{
		if (game->map[game->y - 1][game->x] != WALL)
			game->count_steps++;
	}
	if (keycode == S || keycode == S_ARROW)
	{
		if (game->map[game->y + 1][game->x] != WALL)
			game->count_steps++;
	}		
}