/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:14:44 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/13 14:49:58 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_struct(t_data *data)
{
	data->x = ft_lenline(data);
	data->y = ft_nb_lines(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x * 32, data->y * 32,
		"so_long");
	data->collected = 0;
	data->out = 0;
	data->player = 0;
	data->player_pos.pos_x = 0;
	data->player_pos.pos_y = 0;
	data->player_move = 0;
	data->len = 0;
	data->swords = 0;
	data->map.lenline = 0;
	data->map.nb_lines = 0;
}

int	red_cross(t_data *data)
{
	ft_free_data(data);
	exit(EXIT_FAILURE);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		data.map.map = ft_reading_map(av, 1, -1, 0);
		ft_initialize_struct(&data);
		check_map(&data);
		ft_check_walls(&data);
		if (check_paths(&data, (ft_parse_player_pos_y(&data) / 32),
				(ft_parse_player_pos_x(&data) / 32), ft_swords(&data)) == 0)
			ft_map_error("Error\nInvalid map\n", &data);
		ft_put_background(&data, data.x, data.y);
		ft_put_img(&data, data.x, data.y);
		mlx_hook(data.win, 17, 0, &red_cross, &data);
		mlx_hook(data.win, 2, 0, &ft_keycode, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_putstr_fd("Try like this ./so_long with a map.ber\n", 2);
}
