/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:59:43 by tacampos          #+#    #+#             */
/*   Updated: 2024/02/03 19:42:59 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	formats_check(va_list *args, char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (format == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	if (format == 'p')
		return (ft_ptr_print(va_arg(*args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (format == 'u')
		return (
			ft_putnbr_base_fd(va_arg(*args, unsigned int), "0123456789", 1)
		);
	if (format == 'x')
		return (ft_print_x(va_arg(*args, unsigned int)));
	if (format == 'X')
		return (ft_print_x_upper(va_arg(*args, unsigned int)));
	if (format == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += formats_check(&args, format[i]);
		}
		else
		{
			count += ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
 
/* 
#include <stdio.h>
int	main(void)
{
    int teste;
    int	result;
	int	result1;
    
	printf("Char:\n");
    printf("%c\n", 'T');
    ft_printf("%c\n", 'T');
	printf("\n");

	printf("String:\n");
    printf("%s\n", "The eye of the tiger");
    ft_printf("%s\n", "The eye of the tiger");
	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);
	printf("\n");
    
	printf("Puntero:\n");
    printf("%p\n", &teste);
    ft_printf("%p\n", &teste);
	printf("\n");

	printf("Digit:\n");
    printf("%d\n", 2147483647);
	ft_printf("%d\n", 2147483647);
	printf("\n");
	result1 = printf("%d", -2147483647);
	printf("\n");
    result = ft_printf("%d", -2147483647);
	printf("\n");
	printf("How many chars:\n");
	printf("%d\n", result);	
	printf("%d\n", result1);
	printf("\n");

	printf("Integer:\n");
    printf("%i\n", 2147483647);
	ft_printf("%i\n", 2147483647);
	printf("\n");
	result1 = printf("%i", -2147483647);
	printf("\n");
    result = ft_printf("%i", -2147483647);
	printf("\n");
	printf("How many chars:\n");
	printf("%i\n", result);	
	printf("%i\n", result1);
	printf("\n");

	printf("Unsigned int:\n");
    printf("%u\n", -1);
    ft_printf("%u\n", -1);
    printf("\n");

	printf("Hexadecimal lower:\n");
    printf("%x\n", 12648430);
    ft_printf("%x\n", 12648430);
    printf("\n");
	printf("%x\n", 51966);
    ft_printf("%x\n", 51966);
    printf("\n");

	printf("Hexadecimal Upper:\n");
    printf("%X\n", 12648430);
	ft_printf("%X\n", 12648430);
    printf("\n");
	printf("%x\n", 51966);
    ft_printf("%x\n", 51966);
    printf("\n");
    
	printf("Char %%:\n");
    printf("%%\n");
    ft_printf("%%\n");
    printf("\n");
}
 */