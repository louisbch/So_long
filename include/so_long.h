/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:17:10 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/29 18:43:36 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h> //TO DELETE
# include "../libft/libft.h"

/*--DEFINE TOUCH--*/

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*--struct for xpm and textures--*/

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	
}				t_player;

/*--struct for the map--*/

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		swords;
}				t_map;

/*--struct for the functions--*/

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		player;
	int		collected;
	int		out;
	int		x;
	int		y;
	int		len;
	t_map	map;
	t_player	player_pos;
}				t_data;

/*--FT_IMG.C--*/

void	ft_put_background(t_data data, int size_x, int size_y);
void	ft_put_img(t_data data, int size_x, int size_y);
void	ft_put_img_help(t_data data, int i, int j);

/*--FT_IMG_UTILS.C--*/

void	ft_put_walls(t_data data, int size_x, int size_y);
void	ft_put_player(t_data data, char *str, int size_x, int size_y);
void	ft_put_swords(t_data data, int size_x, int size_y);
void	ft_put_exit(t_data data, int size_x, int size_y);

/*--FT_MAP.C--*/

char	**ft_reading_map(char **av);
void	check_map(t_data data);
void	check_map_help(t_data data);
void	check_char(t_data data, int i, int j);
void	ft_check_walls(t_data data);

/*FT_UTILS.C*/

int		str_last(char *str, char *need, size_t size);
void	ft_map_error(char *str);
void	ft_check_walls_help(t_data data, int i, int j, int count);
int		ft_check_size_of_char(t_data data);
int		ft_check_lines(t_data data);

/*--FT_MAIN.C--*/

void	ft_initialize_struct(t_data *data);

/*--FT_KEY_CODE.C--*/

int		ft_keycode(t_data data, int keycode);

/*--FT_MOVE.C--*/

void	ft_move(t_data data, int keycode);
void	ft_parse_player_pos(t_data data);

/*--FT_FINISH.c--*/

/*--FT_PARSING.C--*/

#endif