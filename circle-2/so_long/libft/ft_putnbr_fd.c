/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:01:26 by tacampos          #+#    #+#             */
/*   Updated: 2024/10/22 20:00:40 by tacampos         ###   ########.fr       */
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
		count += ft_putchar_fd('-', fd);
		long_n = -long_n;
	}
	if (long_n >= 10)
		count += ft_putnbr_fd(long_n / 10, fd);
	count += ft_putchar_fd(long_n % 10 + '0', fd);
	return (count);
}
