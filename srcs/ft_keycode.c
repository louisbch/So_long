/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:58:42 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/10 16:11:04 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_keycode(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == W)
		ft_move(data, keycode);
	else if (keycode == S)
		ft_move(data, keycode);
	else if (keycode == D)
		ft_move(data, keycode);
	else if (keycode == A)
		ft_move(data, keycode);
	return (0);
}
