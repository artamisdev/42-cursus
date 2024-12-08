/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:28:33 by tacampos          #+#    #+#             */
/*   Updated: 2024/12/08 18:42:37 by tacampos         ###   ########.fr       */
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
	int		count_collectible;
	int		count_steps;
	t_img	img;
} t_game;

int load_images(t_game *game);
int deploy_background(t_game *game);
void deploy_p(t_game *game);
void p_reposition(t_game *game);
int	check_width_map(char *file_name);
int	check_valid_char_map(char *file_name);
int	check_exit_map(char *file_name);
int	check_player_map(char *file_name);
int	check_collectibles(char *file_name);
int check_the_side_walls(char *file_name);
int check_char_one(char *read_line);
int check_lower_wall(char *file_name);
int check_upper_wall(char *file_name);
int	count_lines(char *file_name);
int count_collectibles(t_game *game);
void counter_steps(t_game *game, int keycode);

#endif