/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:01:07 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/10 17:56:14 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_data *data, int x, int y)
{
	data->player_move++;
	printf("Player move : %d\n", data->player_move);
	if (data->map.map[y][x] == 'C')
			data->collected++;
	if (data->map.map[y][x] == 'E')
	{
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
		ft_put_exit(data, data->player_pos.pos_x, data->player_pos.pos_y);
		data->map.map[y][x] = 'E';
	}
	else if (data->map.map[y][x] != 'E')
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
	data->player_pos.pos_y -= 32;
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = 'P';
	ft_put_player(data, "./textures/up.xpm", data->player_pos.pos_x,
		data->player_pos.pos_y);
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = '0';
}

void	move_down(t_data *data, int x, int y)
{
	data->player_move++;
	printf("Player move : %d\n", data->player_move);
	if (data->map.map[y][x] == 'C')
		data->collected++;
	if (data->map.map[y][x] == 'E')
	{
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
		ft_put_exit(data, data->player_pos.pos_x, data->player_pos.pos_y);
		data->map.map[y][x] = 'E';
	}
	else if (data->map.map[y][x] != 'E')
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
	data->player_pos.pos_y += 32;
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = 'P';
	ft_put_player(data, "./textures/down.xpm", data->player_pos.pos_x,
		data->player_pos.pos_y);
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = '0';
}

void	move_right(t_data *data, int x, int y)
{
	data->player_move++;
	printf("Player move : %d\n", data->player_move);
	if (data->map.map[y][x] == 'C')
		data->collected++;
	if (data->map.map[y][x] == 'E')
	{
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
		ft_put_exit(data, data->player_pos.pos_x, data->player_pos.pos_y);
		data->map.map[y][x] = 'E';
	}
	else if (data->map.map[y][x] != 'E')
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
	data->player_pos.pos_x += 32;
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = 'P';
	ft_put_player(data, "./textures/right.xpm", data->player_pos.pos_x,
		data->player_pos.pos_y);
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = '0';
}

void	move_left(t_data *data, int x, int y)
{
	data->player_move++;
	printf("Player move : %d\n", data->player_move);
	if (data->map.map[y][x] == 'C')
		data->collected++;
	if (data->map.map[y][x] == 'E')
	{
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
		ft_put_exit(data, data->player_pos.pos_x, data->player_pos.pos_y);
		data->map.map[y][x] = 'E';
	}
	else if (data->map.map[y][x] != 'E')
		ft_put_one_background(data, data->player_pos.pos_x,
			data->player_pos.pos_y);
	data->player_pos.pos_x -= 32;
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = 'P';
	ft_put_player(data, "./textures/left.xpm", data->player_pos.pos_x,
		data->player_pos.pos_y);
	if (data->map.map[y][x] != 'E')
		data->map.map[y][x] = '0';
}
