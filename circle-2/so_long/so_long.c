/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:50 by tacampos          #+#    #+#             */
/*   Updated: 2024/10/23 12:41:04 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int main()
{   
    int     fd;
    char    *line;
    char    **column;
    
    fd = open ("maps/map1.ber", O_RDONLY);
    if (fd < 0)
        return(1);
    
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
