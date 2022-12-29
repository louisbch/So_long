/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:14:33 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/29 18:27:55 by lbouchon         ###   ########.fr       */
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

void	ft_map_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_check_walls_help(t_data data, int i, int j, int count)
{
	if (i == 0 && data.map.map[i][j] != '1')
		ft_map_error("Invalid map\n");
	if (j == 0 && data.map.map[i][j] != '1')
		ft_map_error("Invalid map\n");
	if (i == (count - 1) && data.map.map[i][j] != '1')
		ft_map_error("Invalid map\n");
}

int	ft_check_size_of_char(t_data data)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	len = ft_strlen(data.map.map[i]);
	return (len);
}

int	ft_check_lines(t_data data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data.map.map[i])
	{
		i++;
		count++;
	}
	return (count);
}
