/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:57:06 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 17:57:00 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_win(t_data *data)
{
	ft_free_data(data);
	ft_putstr_fd("Congratulations ! You won\n", 1);
	exit(EXIT_SUCCESS);
}

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
