/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:14:44 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/04 12:52:15 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_struct(t_data *data)
{
	data->mlx = mlx_init();
	data->collected = 0;
	data->out = 0;
	data->player = 0;
	data->player_pos.pos_x = 0;
	data->player_pos.pos_y = 0;
	data->len = 0;
	data->x = 0;
	data->y = 0;
}

int	red_cross(void)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		size_x;
	int		size_y;
	int		i;
	i = 0;

	if (ac == 2)
	{
		data.map.map = ft_reading_map(av);
		size_x = ft_check_size_of_char(av);
		size_y = ft_check_lines(av);
		ft_initialize_struct(&data);
		check_map(&data);
		ft_check_walls(&data);
		data.win = mlx_new_window(data.mlx, size_x * 32, size_y * 32, "so_long");
		ft_put_background(&data, size_x, size_y);
		ft_put_img(&data, size_x, size_y);
		mlx_hook(data.win, 17, 0, &red_cross, &data);
		mlx_hook(data.win, 2, 0, &ft_keycode, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_putstr_fd("Try like this ./so_long with a map.ber\n", 2);
}
