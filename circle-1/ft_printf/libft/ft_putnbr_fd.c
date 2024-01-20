/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:01:26 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/20 17:37:08 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	long_n;
	int		count;

	count = 0;
	long_n = n;
	if (long_n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n = -long_n;
	}
	if (long_n >= 10)
		ft_putnbr_fd(long_n / 10, fd);
	count += ft_putchar_fd(long_n % 10 + '0', fd);
	return (count);
}
