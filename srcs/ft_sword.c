/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sword.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:37:31 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 18:19:30 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_swords(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'C')
				data->swords++;
			j++;
		}
		i++;
	}
	return (data->swords);
}

void	ft_rectangular(t_data *data)
{
	int	lenline;
	int	i;

	lenline = ft_lenline(data);
	i = 0;
	while (data->map.map[i])
	{
		if ((int)ft_strlen(data->map.map[i]) != lenline)
			ft_map_error("Error\nMap is not rectangular\n", data);
		i++;
	}
}

int	ft_strlenback(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	ft_open_map(char **av, int fd)
{
	if (str_last(av[1], ".ber", 4) != 0)
		ft_invalid("Error\nYour map need to finish with .ber\n");
	if (fd < 0)
		ft_invalid("Error\nBad file\n");
}
