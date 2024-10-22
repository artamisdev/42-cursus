/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:50 by tacampos          #+#    #+#             */
/*   Updated: 2024/10/22 20:51:50 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int main()
{   
    int     fd;
    char    *line;
    fd = open ("maps/map2.ber", O_RDONLY);
    
    line = get_next_line(fd);
    while (line != NULL)
    {
        ft_printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    
    return(0);
}