/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:01:01 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/18 15:02:19 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_print_x(va_list args)
{
    unsigned int    value;
    size_t          to_return;

    to_return = 0;
    value = va_arg(args, unsigned int);
    to_return += ft_putnbr_fd(value, "0123456789abcdef", 1);
    return (to_return);
}

size_t	ft_print_x_upper(va_list args)
{
    unsigned int    value;
    size_t          to_return;
    
    to_return = 0;
    value = va_arg(args, unsigned int);
    to_return += ft_putnbr_fd(value, "0123456789ABCDEF", 1);
    return (to_return);
}
