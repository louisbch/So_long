/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:14:44 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/29 18:45:39 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_struct(t_data *data)
{
	data->collected = 0;
	data->out = 0;
	data->player = 0;
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

	if (ac == 2)
	{
		data.map.map = ft_reading_map(av);
		ft_initialize_struct(&data);
		check_map(data);
		ft_check_walls(data);
		size_x = ft_check_size_of_char(data);
		size_y = ft_check_lines(data);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, size_x * 32, size_y * 32, "so_long");
		ft_put_background(data, size_x, size_y);
		ft_put_img(data, size_x, size_y);
		mlx_hook(data.win, 17, 0, &red_cross, &data);
		mlx_hook(data.win, 2, 0, &ft_keycode, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_putstr_fd("Try like this ./so_long with a map.ber\n", 2);
}

/*int main(int ac, char **av)
{
	t_data	data;
	t_map	map;
	int i;
	int	c;
	int	x;
	int	y;
	int	size_x;
	int	size_y;
	void *nothing;

	y = 0;
	x = 0;
	if (ac == 4)
		printf("cool");	
	data.map.map = ft_reading_map(av);
	size_x = ft_check_size_of_char(&map);
	printf("%d\n", size_x);
	size_y = ft_check_lines(&map);
	data.mlx = mlx_init(); 
	data.win = mlx_new_window(data.mlx, size_x * IMG_H, size_y *IMG_W, "so_long");
	while (y < size_y * 32)
	{
		x = 0;
		while (x < size_x * 32)
		{
			nothing = mlx_xpm_file_to_image(data.mlx, "./textures/background.xpm", &c, &i);
			mlx_put_image_to_window(data.mlx, data.win, nothing, x, y);
			printf("%d\n", x);
			x += 32;
			if (x == size_x)
				break;
		}
		y += 32;
	}
	mlx_loop(data.mlx);
}*/