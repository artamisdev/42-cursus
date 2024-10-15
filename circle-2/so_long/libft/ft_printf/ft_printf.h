/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:29:16 by tacampos          #+#    #+#             */
/*   Updated: 2024/01/04 16:22:26 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
size_t	ft_ptr_print(void *ptr);
size_t	ft_putnbr_base_fd(unsigned long n, char *base, int fd);
size_t	ft_putnbr_base_fd_long(long n, char *base, int fd);
size_t	ft_print_x(unsigned int value);
size_t	ft_print_x_upper(unsigned int value);

#endif