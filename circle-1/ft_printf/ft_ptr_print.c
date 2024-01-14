/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:11:30 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/14 18:11:34 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ptr_print(va_list args)
{
    unsigned long  value;
    int to_return;

    value = (unsigned long)va_arg(args, void *);
    to_return = 0;

    to_return += write(1, "0x", 2);
    to_return += ft_putnbr_base_fd(value, "0123456789abcdef", 1);

    return (to_return);

}
