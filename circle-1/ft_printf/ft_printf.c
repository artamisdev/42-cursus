/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:59:43 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/18 14:56:17 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	formats_check(va_list *args, char format)
{
    if (format == 'c')
        ft_putchar_fd(va_arg(*args, int), 1);
    if (format == 's')
        ft_putstr_fd(va_arg(*args, char *), 1);
    if (format == 'p'){}
       // ft_ptr_print(va_arg(*args, void *));
    if (format == 'd' || format == 'i')
        ft_putnbr_fd(va_arg(*args, int), 1);
    if (format == 'u')
        ft_putnbr_fd(va_arg(*args, unsigned int), 1);
    if (format == 'x')
        ft_print_x(va_arg(*args, unsigned int));
    if (format == 'X')
        ft_print_x_upper(va_arg(*args, unsigned int));
    if (format == '%')
        ft_putchar_fd('%', 1);
}

int	ft_printf(char const *format, ...)
{
    va_list args;
    int     i;
    i = 0;
    va_start(args, format);
    while (format[i])
    {

        if (format[i] == '%')
        {
            i++;
            formats_check(&args, format[i]);
        }                                                                                                                                                                                                            
        else ft_putchar_fd(format[i], 1);
        i++;
    }
    va_end(args);
    return(0);
}

int main(void)
{
    printf("%x, %X, Hello %c, %s, %d, %i , %u, %%\n", 1748, 1748, 'T', "amires", 20, 7, 25465);
    ft_printf("%x, %X, Hello %c, %s, %d, %i , %u, %%\n", 1748, 1748, 'T', "amires", 20, 7, 25465);    
}
