/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:51:00 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/13 15:00:26 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	free(data->map.map);
}

void	ft_invalid(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_open_map(char **av, int fd)
{
	if (str_last(av[1], ".ber", 4) != 0)
		ft_invalid("Error\nYour map need to finish with .ber\n");
	if (fd < 0)
		ft_invalid("Error\nBad file\n");
}

void	ft_reading_help(int fd, int j, char **map, char *line)
{
	line = get_next_line(fd);
	map[j] = line;
	map[j][ft_strlenback(map[j])] = '\0';	
}
