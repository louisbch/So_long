/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:53:32 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 11:27:08 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int nb)
{
	int		len;
	char	*result;

	len = ft_unsigned_len(nb);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (nb != 0)
	{
		result[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (result);
}

int	ft_print_unsigned(unsigned int nb)
{
	int		len;
	char	*n;

	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		n = ft_utoa(nb);
		len += ft_printstr(n);
		free(n);
	}
	return (len);
}
