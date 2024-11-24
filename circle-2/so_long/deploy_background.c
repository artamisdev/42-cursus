/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:10:28 by tacampos          #+#    #+#             */
/*   Updated: 2024/11/24 17:58:10 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int load_images(t_game *game, t_img *img)
{
    int x;
    int y;

    img->walls = mlx_xpm_file_to_image(game->mlx_ptr, WALL_PATH, &x, &y);
    img->player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_PATH, &x, &y);
    img->collectable = mlx_xpm_file_to_image(game->mlx_ptr, COLLECTABLE_PATH, &x, &y);
    img->exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_PATH, &x, &y);
    // etc ...
    // if (!img.walls)
        // LIBERAR Y SALIR
    return (EXIT_SUCCESS);
}   

int deploy_background(t_game *game, t_img *img, char **map)
{
    int i;
    int j;

    i = 0;
    while (map && map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->walls, j * PIXEL_SIZE, i * PIXEL_SIZE);
            if (map[i][j] == 'P')
            {
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->player, j * PIXEL_SIZE, i * PIXEL_SIZE);
                game->x = j;
                game->y = i;
            }
            if (map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->collectable, j * PIXEL_SIZE, i * PIXEL_SIZE);
            if (map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->exit, j * PIXEL_SIZE, i * PIXEL_SIZE);
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}