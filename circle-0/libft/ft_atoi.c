/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:51:43 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/25 17:57:38 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}
