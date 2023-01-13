/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:17:10 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/13 11:07:24 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
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

typedef struct s_path
{
	int		coins;
	int		exit;
}				t_path;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
}				t_player;

typedef struct s_map
{
	char	**map;
	int		lenline;
	int		nb_lines;

}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			player;
	int			player_move;
	int			collected;
	int			swords;
	int			out;
	int			x;
	int			y;
	int			len;
	t_map		map;
	t_player	player_pos;
}				t_data;

/*--FT_IMG.C--*/

void	ft_put_background(t_data *data, int size_x, int size_y);
void	ft_put_img(t_data *data, int size_x, int size_y);
void	ft_put_img_help(t_data *data, int i, int j);

/*--FT_IMG_UTILS.C--*/

void	ft_put_walls(t_data *data, int size_x, int size_y);
void	ft_put_player(t_data *data, char *str, int size_x, int size_y);
void	ft_put_swords(t_data *data, int size_x, int size_y);
void	ft_put_exit(t_data *data, int size_x, int size_y);
void	ft_put_one_background(t_data *data, int size_x, int size_y);

/*--FT_MAP.C--*/

char	**ft_reading_map(char **av, int i, int j, int fd);
void	check_map(t_data *data);
void	check_map_help(t_data *data);
void	check_char(t_data *data, int i, int j);
void	ft_check_walls(t_data *data);

/*FT_UTILS.C*/

int		str_last(char *str, char *need, size_t size);
void	ft_map_error(char *str, t_data *data);
void	ft_check_walls_help(t_data *data, int i, int j, int count);
int		ft_nb_lines(t_data *data);
int		ft_lenline(t_data *data);

/*--MAIN.C--*/

void	ft_initialize_struct(t_data *data);
void	ft_init_tab(t_data *data, char **av);

/*--FT_KEY_CODE.C--*/

int		ft_keycode(int keycode, t_data *data);

/*--FT_MOVE.C--*/

void	ft_move(t_data *data, int keycode);
int		ft_parse_player_pos_x(t_data *data);
int		ft_parse_player_pos_y(t_data *data);

/*--FT_MOVE.C--*/

void	move_up(t_data *data, int x, int y);
void	move_down(t_data *data, int x, int y);
void	move_right(t_data *data, int x, int y);
void	move_left(t_data *data, int x, int y);

/*--FT_SWORD.C--*/

int		ft_swords(t_data *data);
void	ft_rectangular(t_data *data);
int		ft_strlenback(char *str);
void	ft_open_map(char **av, int fd);

/*--FT_WIN.C--*/

void	ft_win(t_data *data);
void	ft_free_data(t_data *data);
void	ft_invalid(char *str);

/*--FT_PATH.C--*/

int		check_paths(t_data *data, int pos_y, int pos_x, int collected);
char	**duplicate_map(t_data *data);
void	ft_path_help(t_path *path, char **map, int y, int x);
void	ft_path(t_path *path, char **map, int y, int x);

#endif