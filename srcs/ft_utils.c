/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:12:17 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/22 14:49:06 by lbouchon         ###   ########.fr       */
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
