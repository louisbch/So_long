/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:48:41 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/27 11:32:58 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_reading_map(char **av)
{
	char	*line;
	char	*all_lines;
	int		fd;

	if (str_last(av[1], ".ber", 4) != 0)
		ft_map_error("Your map need to finish with .ber\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
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

void	check_map(t_map *map, t_data data)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strnstr(map->map[i], "E", ft_strlen(map->map[i])))
			data.out++;
		if (ft_strnstr(map->map[i], "P", ft_strlen(map->map[i])))
			data.player++;
		if (ft_strnstr(map->map[i], "C", ft_strlen(map->map[i])))
			data.collected++;
		i++;
	}
	if (data.player != 1)
		ft_map_error("Need only one player !\n");
	if (data.collected < 1)
		ft_map_error("Need at least one collectible !\n");
	if (data.out != 1)
		ft_map_error("Need only exit !\n");
	check_map_help(map);
}

void	check_map_help(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			check_char(map, i , j);
			j++;
			if (map->map[i][j] < len)
			{
				j = 0;
				break ;
			}
		}
		i++;
	}
}

void	check_char(t_map *map, int i, int j)
{
	if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'C'
		&& map->map[i][j] != 'E' && map->map[i][j] != 'P')
		ft_map_error("Not accept this character only 1,0,C,P,E\n");
}

void	ft_check_walls(t_map *map)
{
	int	len;
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	len = ft_strlen(map->map[i]);
	i = 0;
	printf("%d\n", count);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i == 0 && map->map[i][j] != '1') 
				ft_map_error("Invalid map\n");
			if (j == 0 && map->map[i][j] != '1')
				ft_map_error("Invalid map\n");
			if (i == count && map->map[i][j] != '1')
				ft_map_error("Invalid map\n");
			j++;
			if (map->map[i][j] == len)
			{
				if (map->map[i][j] != '1')
					ft_map_error("Invalid map\n");
				break ;
			}
		}
		printf("%s\n", map->map[i]);
		i++;
	}
	--i;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			ft_map_error("Invalid map \n");
		if (map->map[i][j + 1] == '\n')
			return ;
		j++;
	}
}
