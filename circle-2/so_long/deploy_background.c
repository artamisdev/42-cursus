/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:10:28 by tacampos          #+#    #+#             */
/*   Updated: 2024/12/08 18:50:07 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int load_images(t_game *game)
{
    int x;
    int y;

    game->img.walls = mlx_xpm_file_to_image(game->mlx_ptr, WALL_PATH, &x, &y);
    game->img.player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_PATH, &x, &y);
    game->img.collectable = mlx_xpm_file_to_image(game->mlx_ptr, COLLECTABLE_PATH, &x, &y);
    game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_PATH, &x, &y);
    // etc ...
    if (!game->img.player)
        return ft_printf("Cannot Cannot access images!\n");
    if (!game->img.collectable)
        return ft_printf("Cannot Cannot access images!\n");
    if (!game->img.exit)
        return ft_printf("Cannot Cannot access images!\n");
    if (!game->img.walls)
        return ft_printf("Cannot Cannot access images!\n");
        // LIBERAR Y SALIR
    return (EXIT_SUCCESS);
}   

int deploy_background(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map && game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.walls, j * PIXEL_SIZE, i * PIXEL_SIZE);
            if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.collectable, j * PIXEL_SIZE, i * PIXEL_SIZE);
            if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, j * PIXEL_SIZE, i * PIXEL_SIZE);
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}
void p_reposition(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    while (game->map && game->map[i])
    {
        
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, j * PIXEL_SIZE, i * PIXEL_SIZE);
                game->x = j;
                game->y = i;
            }
            j++;
        }
        i++;
    }   
}
void deploy_p(t_game *game)
{
    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    deploy_background(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->x * PIXEL_SIZE, game->y * PIXEL_SIZE);
}
