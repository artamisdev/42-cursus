/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:51:43 by tacampos          #+#    #+#             */
/*   Updated: 2023/10/15 18:36:14 by tacampos         ###   ########.fr       */
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

/*#include <stdio.h>

int main(void)
{
	char	a[] = "-123";
	char	b[] = "123";
	char	c[] = "-+123";
	char	d[] = "-abc123";
	char	e[] = "1a2b3c";
	char	f[] = "+123";
	char	g[] = "+abc1";
	char	h[] = "12+34";
	char	i[] = "       +4321";
	char	j[] = "   -    4321";

	printf("Result_ft_a: %d\n", ft_atoi(a));
	printf("Result_ft_b: %d\n", ft_atoi(b));
	printf("Result_ft_c: %d\n", ft_atoi(c));
	printf("Result_ft_d: %d\n", ft_atoi(d));
	printf("Result_ft_e: %d\n", ft_atoi(e));
	printf("Result_ft_f: %d\n", ft_atoi(f));
	printf("Result_ft_g: %d\n", ft_atoi(g));
	printf("Result_ft_h: %d\n", ft_atoi(h));
	printf("Result_ft_i: %d\n", ft_atoi(i));
	printf("Result_ft_j: %d\n", ft_atoi(j));
	printf("\n");
	printf("Result_atoi_a: %d\n", atoi(a));
	printf("Result_atoi_b: %d\n", atoi(b));
	printf("Result_atoi_c: %d\n", atoi(c));
	printf("Result_atoi_d: %d\n", atoi(d));
	printf("Result_atoi_e: %d\n", atoi(e));
	printf("Result_atoi_f: %d\n", atoi(f));
	printf("Result_atoi_g: %d\n", atoi(g));
	printf("Result_atoi_h: %d\n", atoi(h));
	printf("Result_atoi_i: %d\n", atoi(i));
	printf("Result_atoi_j: %d\n", atoi(j));
}*/
