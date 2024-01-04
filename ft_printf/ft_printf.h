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

typedef struct s_flags
{
	int		left_align;
	char	pad_char;
	int		precision;
	int		min_width;
	int		hex_form;
	int		space_sign;
	int		signed_form;
}	t_flags;

int		ft_printf(const char *format, ...);
