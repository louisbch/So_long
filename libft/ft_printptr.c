/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:43:40 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 11:27:21 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

void	ft_putptr(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_printchar(nb + '0');
		else
			ft_printchar(nb - 10 + 'a');
	}
}

int	ft_printptr(unsigned long nb)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (nb == 0)
		len += write(1, "0", 1);
	else
		ft_putptr(nb);
		len += ft_ptr_len(nb);
	return (len);
}
