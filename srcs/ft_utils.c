/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:14:33 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/13 14:55:15 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	str_last(char *str, char *need, size_t size)
{
	if (ft_strlen(str) < size || ft_strlen(need) < size)
		return (-1);
	return (ft_strncmp(str + ft_strlen(str) - size,
			need + ft_strlen(need) - size, size));
}

void	ft_map_error(char *str, t_data *data)
{
	ft_free_data(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_check_walls_help(t_data *data, int i, int j, int count)
{
	if (i == 0 && data->map.map[i][j] != '1')
		ft_map_error("Error\nWrong walls\n", data);
	if (j == 0 && data->map.map[i][j] != '1')
		ft_map_error("Error\nWrong walls\n", data);
	if (i == (count - 1) && data->map.map[i][j] != '1')
		ft_map_error("Error\nWrong walls\n", data);
}

int	ft_lenline(t_data *data)
{
	int		i;

	i = 0;
	data->map.lenline = ft_strlen(data->map.map[i]);
	return (data->map.lenline);
}

int	ft_nb_lines(t_data *data)
{
	int		i;

	i = -1;
	while (data->map.map[++i])
		data->map.nb_lines++;
	return (data->map.nb_lines);
}
