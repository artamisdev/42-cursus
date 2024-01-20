/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:01:01 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/20 17:09:33 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_print_x(unsigned int value)
{
	size_t	to_return;

	to_return = 0;
	to_return += ft_putnbr_base_fd(value, "0123456789abcdef", 1);
	return (to_return);
}

size_t	ft_print_x_upper(unsigned int value)
{
	size_t	to_return;

	to_return = 0;
	to_return += ft_putnbr_base_fd(value, "0123456789ABCDEF", 1);
	return (to_return);
}
