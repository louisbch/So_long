/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:17:10 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/27 15:46:34 by lbouchon         ###   ########.fr       */
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

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

/*--struct for xpm and textures--*/

typedef struct s_img
{
	void	*up_link;
	void	*left_link;
	void	*right_link;
	void	*down_link;
	void	*backgrounds;
}				t_img;

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
}				t_data;

/*--FT_IMG.C--*/

/*--FT_MAP.C--*/

char	**ft_reading_map(char **av);
void	check_map(t_map *map, t_data data);
void	check_map_help(t_map *map);
void	check_char(t_map *map, int i, int j);
void	ft_check_walls(t_map *map);

/*FT_UTILS.C*/

int		str_last(char *str, char *need, size_t size);
void	ft_map_error(char *str);
void	ft_check_walls_help(t_map *map, int i, int j, int count);

/*--FT_MAIN.C--*/

void	ft_initialize_struct(t_data *data);

/*--FT_INIT.C--*/

/*--FT_KEY_HOOK.C--*/

/*--FT_MOVE--*/

/*--FT_FINISH.c--*/

/*--FT_PARSING.C--*/

#endif