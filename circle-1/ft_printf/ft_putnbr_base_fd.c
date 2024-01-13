/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:31:54 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/13 18:32:23 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbr_base_fd(unsigned long n, char *base, int fd)
{
	size_t	i;

	if (n < (unsigned long)ft_strlen(base))
		i += ft_putchar_fd(base[n], 1);
	else
	{
		i += ft_putnbr_base_fd(n / ft_strlen(base), base, fd);
		i += ft_putnbr_base_fd(n % ft_strlen(base), base, fd); 
	}
	return (i);
}

size_t	ft_putnbr_base_fd_long(long n, char *base, int fd)
{
	size_t	i;

	if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n < (long)ft_strlen(base))
		i += ft_putchar_fd(base[n], 1);
	else 
	{
		i += ft_putnbr_base_fd_long(n / ft_strlen(base), base, fd);
		i += ft_putnbr_base_fd_long(n % ft_strlen(base), base, fd);
	}
	return (i);
}