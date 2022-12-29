/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:13:10 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/29 18:45:01 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_parse_player_pos(t_data data, char **av)
{
	int	i;
	int	j;

	i = 0;
	data.map.map = ft_reading_map(av);
	printf("%s\n", data.map.map[0]);
	printf("Hello\n");
	while (data.map.map[i])
	{
		j = -1;
		while (data.map.map[i][++j])
		{
			if (data.map.map[i][j] == 'P')
			{
				data.player_pos.pos_x = j * 32;
				data.player_pos.pos_y = i * 32;
				printf("x = %d\ty = %d\n", data.player_pos.pos_x, data.player_pos.pos_y);
			}
			if (j == data.len - 1)
				break ;
		}
		printf("%s\n", data.map.map[i]);
		i++;
	}	
}

void	ft_move(t_data data, int keycode)
{
	printf("Bonjour\n");
	ft_parse_player_pos(data);
	printf("x = %d\n", data.player_pos.pos_x);
	printf("x = %d\n", data.player_pos.pos_y);
	if (keycode == W)
	{
		ft_put_background(data, data.player_pos.pos_x, data.player_pos.pos_y);
		data.player_pos.pos_x -= 32;
		ft_put_player(data, "./textures/right.xpm", data.player_pos.pos_x, data.player_pos.pos_x);
	}
}
