/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:48:41 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 10:50:16 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_reading_map(char **av)
{
	char	*line;
	int		fd;
	char	*all_lines;

	all_lines = ft_strdup("");
	if (!all_lines)
		return (NULL);
	if (str_last(av[1], ".ber", 4) != 0)
		ft_map_error("Error\nYour map need to finish with .ber\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_map_error("Error\nBad file\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (!all_lines)
		exit(EXIT_FAILURE);
	return (ft_split(all_lines, '\n'));
}

void	check_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		if (ft_strnstr(data->map.map[i], "E", ft_strlen(data->map.map[i])))
			data->out++;
		if (ft_strnstr(data->map.map[i], "P", ft_strlen(data->map.map[i])))
			data->player++;
		if (ft_strnstr(data->map.map[i], "C", ft_strlen(data->map.map[i])))
			data->collected++;
		i++;
	}
	if (data->player != 1)
		ft_map_error("Error\nNeed only one player !\n");
	if (data->collected < 1)
		ft_map_error("Error\nNeed at least one collectible !\n");
	if (data->out != 1)
		ft_map_error("Error\nNeed only one exit !\n");
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
		ft_map_error("Error\nNot accept this character only 1,0,C,P,E\n");
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
					ft_map_error("Error\nInvalid map04\n");
				break ;
			}
		}
		i++;
	}
}
