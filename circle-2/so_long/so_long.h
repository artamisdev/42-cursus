/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:28:33 by tacampos          #+#    #+#             */
/*   Updated: 2024/11/20 14:37:07 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

#define ESC 65307
#define A 97
#define W 119
#define S 115
#define D 100
#define A_ARROW 65361
#define W_ARROW 65362
#define S_ARROW 65364
#define D_ARROW 65363
#define	PIXEL_SIZE 64

#define WALL_PATH "assets/1-trees.xpm"
#define PLAYER_PATH "assets/p-move.xpm"
#define COLLECTABLE_PATH "assets/strawberry.xpm"
#define EXIT_PATH "assets/exit.xpm"

typedef struct s_img
{
	void *walls;
	void *collectable;
	void *player;
	void *exit;
} t_img;


typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
} t_game;


int load_images(t_game *game, t_img *img);
int deploy_background(t_game *game, t_img *img, char **map);

#endif