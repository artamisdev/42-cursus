/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:28:33 by tacampos          #+#    #+#             */
/*   Updated: 2024/11/28 20:33:51 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ESC 65307
# define A 97
# define W 119
# define S 115
# define D 100
# define A_ARROW 65361
# define W_ARROW 65362
# define S_ARROW 65364
# define D_ARROW 65363
# define PIXEL_SIZE 64

# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define GROUND '0'

# define WALL_PATH "assets/1-trees.xpm"
# define PLAYER_PATH "assets/p-move.xpm"
# define COLLECTABLE_PATH "assets/strawberry.xpm"
# define EXIT_PATH "assets/exit.xpm"

typedef struct s_img
{
	void *walls;
	void *collectable;
	void *player;
	void *exit;
} t_img;


typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		x;
	int		y;
	t_img	img;
} t_game;

int load_images(t_game *game);
int deploy_background(t_game *game);
void deploy_p(t_game *game);
void p_reposition(t_game *game);

#endif