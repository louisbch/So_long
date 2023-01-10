/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:14:33 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/10 16:08:26 by lbouchon         ###   ########.fr       */
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

void	ft_check_walls_help(t_data *data, int i, int j, int count)
{
	if (i == 0 && data->map.map[i][j] != '1')
		ft_map_error("Invalid map\n");
	if (j == 0 && data->map.map[i][j] != '1')
		ft_map_error("Invalid map\n");
	if (i == (count - 1) && data->map.map[i][j] != '1')
		ft_map_error("Invalid map\n");
}

int	ft_check_size_of_char(char **av)
{
	int		i;
	char	**my_tab;
	int		len;

	i = 0;
	my_tab = ft_reading_map(av);
	len = ft_strlen(my_tab[i]);
	return (len);
}

int	ft_check_lines(char **av)
{
	int		i;
	int		count;
	char	**my_tab;

	i = 0;
	count = 0;
	my_tab = ft_reading_map(av);
	while (my_tab[i])
	{
		i++;
		count++;
	}
	return (count);
}
