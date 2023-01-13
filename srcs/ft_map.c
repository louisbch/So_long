/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:48:41 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/13 12:23:32 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_reading_map(char **av, int i, int j, int fd)
{
	char	**map;
	char	*line;

	fd = open(av[1], O_RDONLY);
	ft_open_map(av, fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	map = malloc((i + 2) * sizeof(char *));
	if (!map)
		return (NULL);
	close(fd);
	fd = open(av[1], O_RDONLY);
	while (++j < i - 1)
	{
		line = get_next_line(fd);
		map[j] = line;
		map[j][ft_strlenback(map[j])] = '\0';
	}
	close(fd);
	map[j] = NULL;
	return (map);
}

void	check_map(t_data *data)
{
	int	i;
	int	collected;

	i = 0;
	collected = 0;
	while (data->map.map[i])
	{
		if (ft_strnstr(data->map.map[i], "E", ft_strlen(data->map.map[i])))
			data->out++;
		if (ft_strnstr(data->map.map[i], "P", ft_strlen(data->map.map[i])))
			data->player++;
		if (ft_strnstr(data->map.map[i], "C", ft_strlen(data->map.map[i])))
			collected++;
		ft_rectangular(data);
		i++;
	}
	if (data->player != 1)
		ft_map_error("Error\nNeed only one player !\n", data);
	if (collected < 1)
		ft_map_error("Error\nNeed at least one collectible !\n", data);
	if (data->out != 1)
		ft_map_error("Error\nNeed only one exit !\n", data);
	check_map_help(data);
}

void	check_map_help(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			check_char(data, i, j);
			j++;
		}
		i++;
	}
}

void	check_char(t_data *data, int i, int j)
{
	if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0'
		&& data->map.map[i][j] != 'C'
		&& data->map.map[i][j] != 'E' && data->map.map[i][j] != 'P')
		ft_map_error("Error\nNot accept this character only 1,0,C,P,E\n", data);
}

void	ft_check_walls(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	data->len = ft_strlen(data->map.map[i]);
	while (data->map.map[count])
		count++;
	while (data->map.map[i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			ft_check_walls_help(data, i, j, count);
			if (j == data->len - 1)
			{
				if (data->map.map[i][j] != '1')
					ft_map_error("Error\nInvalid map\n", data);
				break ;
			}
		}
		i++;
	}
}
