/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:11:30 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/20 17:34:19 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_ptr_print(void *ptr)
{
	unsigned long	value;
	int				to_return;

	value = (unsigned long)ptr;
	to_return = 0;
	to_return += write(1, "0x", 2);
	to_return += ft_putnbr_base_fd(value, "0123456789abcdef", 1);
	return (to_return);
}