/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:48:41 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/22 16:01:43 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_reading_map(char **av)
{
	char	*line;
	char	*all_lines;
	int		fd;

	if (str_last(av[1], ".ber", 4) != 0)
	{
		ft_putstr_fd("Your map need to finish with .ber\n", 1);
		exit(EXIT_FAILURE);
	}
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

void	check_map(t_map *map)
{
	int	player;
	int	collectible;
	int	out;
	int	i;

	player = 0;
	collectible = 0;
	out = 0;
	i = 0;
	while (map->map[i])
	{
		if (ft_strnstr(map->map[i], "E", ft_strlen(map->map[i])))
			out++;
		if (ft_strnstr(map->map[i], "P", ft_strlen(map->map[i])))
			player++;
		if (ft_strnstr(map->map[i], "C", ft_strlen(map->map[i])))
			collectible++;
		i++;
	}
	check_map_help(map);
	if (player != 1 || collectible < 1 || out != 1)
	{
		printf("sorry bad map\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map_help(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		printf("bonjour\n");
			ft_putstr_fd("This character is not accepted by so_long\n", 1);
			exit(EXIT_FAILURE);
		i++;
	}
}
