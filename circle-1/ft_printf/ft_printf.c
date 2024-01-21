/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:59:43 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/21 17:48:56 by tacampos         ###   ########.fr       */
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
    printf("%p\n", &teste);
    printf("%x\n", 1748);
    printf("%X\n", 1748);
    printf("%c\n", 't');
    printf("%s\n", "amires");
    printf("%d\n", 20);
    printf("%i\n", 9); 
    printf("%u\n", 25267749);
    printf("%%\n");

    printf("\n");

    ft_printf("%p\n", &teste);
    ft_printf("%x\n", 1748);
    ft_printf("%X\n", 1748);
    ft_printf("%c\n", 'T');
    ft_printf("%s\n", "amires");
    ft_printf("%d\n", 20);
    ft_printf("%i\n", 9); 
    ft_printf("%u\n", 25267749);
    ft_printf("%%\n");

	int	result;
	int	result1;

	result = ft_printf("%d", -6000023);
	printf("\n");
	result1 = printf("%d", -6000023);
	printf("\n");
	
	printf("%d\n", result);	
	printf("%d\n", result1);

	printf("%s", NULL);
	printf("\n");
	ft_printf("%s", NULL);
}
*/
