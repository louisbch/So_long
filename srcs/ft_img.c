/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:55:02 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 10:47:46 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_background(t_data *data, int size_x, int size_y)
{
	int		width;
	int		heigth;
	int		x;
	int		y;
	void	*background;

	y = 0;
	while (y < size_y * 32)
	{
		x = 0;
		while (x < size_x * 32)
		{
			background = mlx_xpm_file_to_image(data->mlx,
					"./textures/background.xpm", &width, &heigth);
			if (!background)
				ft_map_error("Error\nBad texture\n");
			mlx_put_image_to_window(data->mlx, data->win, background, x, y);
			x += 32;
			if (x == size_x)
				break ;
		}
		y += 32;
	}
}

void	ft_put_img(t_data *data, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	data->y = 0;
	while (data->map.map[i] && data->y < (size_y * 32))
	{
		j = -1;
		data->x = 0;
		while (data->map.map[i][++j] && data->x < (size_x * 32))
		{
			ft_put_img_help(data, i, j);
			data->x += 32;
			if (data->x == size_x)
				break ;
		}
		i++;
		data->y += 32;
	}
}

void	ft_put_img_help(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == '1')
		ft_put_walls(data, data->x, data->y);
	if (data->map.map[i][j] == 'P')
		ft_put_player(data, "./textures/right.xpm", data->x, data->y);
	if (data->map.map[i][j] == 'C')
		ft_put_swords(data, data->x, data->y);
	if (data->map.map[i][j] == 'E')
		ft_put_exit(data, data->x, data->y);
}
