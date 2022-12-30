/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:37:37 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/30 12:57:25 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_walls(t_data *data, int size_x, int size_y)
{
	void	*walls;
	int		width;
	int		heigth;

	walls = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &width, &heigth);
	mlx_put_image_to_window(data->mlx, data->win, walls, size_x, size_y);
}

void	ft_put_player(t_data *data, char *str, int size_x, int size_y)
{
	void	*link;
	int		width;
	int		heigth;

	link = mlx_xpm_file_to_image(data->mlx,
			str, &width, &heigth);
	mlx_put_image_to_window(data->mlx, data->win, link, size_x, size_y);
}

void	ft_put_swords(t_data *data, int size_x, int size_y)
{
	void	*swords;
	int		width;
	int		heigth;

	swords = mlx_xpm_file_to_image(data->mlx,
			"./textures/sword.xpm", &width, &heigth);
	mlx_put_image_to_window(data->mlx, data->win, swords, size_x, size_y);
}

void	ft_put_exit(t_data *data, int size_x, int size_y)
{
	void	*out;
	int		width;
	int		heigth;

	out = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &width, &heigth);
	mlx_put_image_to_window(data->mlx, data->win, out, size_x, size_y);
}
