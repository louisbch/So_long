/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:58:42 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/29 18:08:03 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_keycode(t_data data, int keycode)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == W)
		ft_move(data, keycode);
	return (0);
}