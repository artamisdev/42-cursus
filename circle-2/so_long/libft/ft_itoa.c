/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:30:15 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/30 19:39:20 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_char(int nb)
{
	long	nbr;
	int		count;

	nbr = nb;
	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static void	fill(char *str, int nb, int size)
{
	long	nbr;
	int		is_negative;

	nbr = nb;
	is_negative = nbr < 0;
	if (is_negative)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (size > is_negative)
	{
		size--;
		str[size] = nbr % 10 + '0';
		nbr /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*n_str;

	size = count_char(n);
	n_str = ft_calloc((size +1), sizeof(char));
	if (!n_str)
		return (NULL);
	fill(n_str, n, size);
	return (n_str);
}
