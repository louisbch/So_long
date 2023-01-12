/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:13:10 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 10:39:58 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_parse_player_pos_x(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'P')
				data->player_pos.pos_x = j * 32;
		}
		i++;
	}
	return (data->player_pos.pos_x);
}

int	ft_parse_player_pos_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'P')
				data->player_pos.pos_y = i * 32;
		}
		i++;
	}
	return (data->player_pos.pos_y);
}

void	ft_move(t_data *data, int keycode)
{
	int	x;
	int	y;

	data->player_pos.pos_x = ft_parse_player_pos_x(data);
	data->player_pos.pos_y = ft_parse_player_pos_y(data);
	x = data->player_pos.pos_x / 32;
	y = data->player_pos.pos_y / 32;
	if (keycode == W && data->map.map[y - 1][x] != '1')
		move_up(data, x, y);
	else if (keycode == S && data->map.map[y + 1][x] != '1')
		move_down(data, x, y);
	else if (keycode == D && data->map.map[y][x + 1] != '1')
		move_right(data, x, y);
	else if (keycode == A && data->map.map[y][x - 1] != '1')
		move_left(data, x, y);
	x = data->player_pos.pos_x / 32;
	y = data->player_pos.pos_y / 32;
	if (data->collected == ft_swords(data) && data->map.map[y][x] == 'E')
		ft_win();
}
