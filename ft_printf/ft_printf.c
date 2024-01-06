/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:59:43 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/06 14:48:30 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static formats_check(va_list *args, char format)
{
    if (format == 'c')
        ft_putchar_fd(va_arg(args,char), 1);
    if (format == 's')
        //ft_putstr_fd()
    if (format == 'p')
        //tipo void *
    if (format == 'd')
        // decimal
    if (format == 'i')
        // tipo inteiro
    if (format == 'u')
        //??????
    if (format == 'x')
        // hexadecimal minusculas
    if (format == 'X')
        // hexadecimal maiusculas
    if (format == '%')
        // caractere de porcentagem
}

int	ft_printf(char const *format, ...)
{
    va_list args;
    int     char_count;
    int     i;

    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            //chamo a funçao de checar
            formats_check(format[i + 1], args)
        }                                                                                                                                                                                                            
        else ft_putchar_fd(format[i], 1);
        i++;
    };
    //iterar sobre cada um dos caracteres de 
    //format e se for igual a % nao imprimir 
    //e ler o proximo prara conferir se é int, char, etc.

    va_end(args);
}
