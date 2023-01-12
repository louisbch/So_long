/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:27:07 by lbouchon          #+#    #+#             */
/*   Updated: 2023/01/12 11:29:08 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_perc(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printnbr(int nb)
{
	int		len;
	char	*n;

	n = ft_itoa(nb);
	len = ft_printstr(n);
	free(n);
	return (len);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	get_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*result;
	long int	nb;

	len = get_len(n);
	nb = n;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	if (n == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (nb)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (result);
}
