/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:57:06 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/13 14:55:51 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_win(t_data *data)
{
	ft_free_data(data);
	ft_putstr_fd("Congratulations ! You won\n", 1);
	exit(EXIT_SUCCESS);
}
