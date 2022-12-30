/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:13:10 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/30 13:54:30 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_parse_player_pos_x(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->len = ft_strlen(data->map.map[i]);
	while (data->map.map[i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->player_pos.pos_x = j * 32;
			}
			if (j == data->len - 1)
				break ;
		}
		printf("%s\n", data->map.map[i]);
		i++;
	}
	return (data->player_pos.pos_x);
}

int	ft_parse_player_pos_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->len = ft_strlen(data->map.map[i]);
	while (data->map.map[i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->player_pos.pos_y = i * 32;
			}
			if (j == data->len - 1)
				break ;
		}
		printf("%s\n", data->map.map[i]);
		i++;
	}
	return (data->player_pos.pos_y);
}

void	ft_move(t_data *data, int keycode)
{
	printf("Salut\n");
	printf("%d\n", data->player_pos.pos_x);
	data->player_pos.pos_x = ft_parse_player_pos_x(data);
	data->player_pos.pos_y = ft_parse_player_pos_y(data);
	printf("x = %d\n", data->player_pos.pos_x);
	printf("x = %d\n", data->player_pos.pos_y);
	if (keycode == W)
	{
		ft_put_background(data, data->player_pos.pos_x, data->player_pos.pos_y);
		data->player_pos.pos_x -= 32;
		ft_put_player(data, "./textures/right.xpm", data->player_pos.pos_x, data->player_pos.pos_x);
	}
}
