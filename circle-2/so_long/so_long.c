/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:50 by tacampos          #+#    #+#             */
/*   Updated: 2024/10/26 17:58:56 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int count_lines(void)
{
    int     fd;
    int     line_count;
    char    *line;
    
    fd = open ("maps/map1.ber", O_RDONLY);
     if (fd < 0)
        return(1);
        
    line_count = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        line_count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
   //ft_printf("\n%d",line_count);
    return(line_count);
}

int main()
{   
    int     fd;
    int     i;
    size_t  line_count;
    char    *line;
    char    **map;
    
    fd = open ("maps/map1.ber", O_RDONLY);
    if (fd < 0)
        return(1);
    line_count = count_lines();
    map = ft_calloc(line_count, sizeof(char*));
    if (!map)
        return(1);
    i = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        map[i] = line;
        ft_printf("%s", line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return(0);
}
