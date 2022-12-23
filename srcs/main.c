/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:14:59 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/23 15:39:43 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_struct(t_data *data)
{
	data->collected = 0;
	data->out = 0;
	data->player = 0;
}

void	ft_print_map(t_map *map)
{
	for (int i = 0; map->map[i]; i++)
		printf("%s\n", map->map[i]);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac == 2)
	{
		ft_initialize_struct(&data);
		map.map = ft_reading_map(av);
		check_map(&map, data);
		ft_check_walls(&map);
		//ft_print_map(&map);
		data.mlx = mlx_init();
		//data.win = mlx_new_window(data.mlx, 1080, 1080, "so_long");
		//mlx_xpm_file_to_image(data.mlx, "./textures/down.xpm", &img_width, &img_height);
		//mlx_put_image_to_window(data.mlx, data.win, data.img->up_link, data.p_x, data.p_y);
		//mlx_loop(data.mlx);
	}
	else
		ft_putstr_fd("Try like this ./so_long with a map.ber\n", 1);
}
