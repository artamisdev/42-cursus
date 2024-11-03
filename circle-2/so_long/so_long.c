/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:50 by tacampos          #+#    #+#             */
/*   Updated: 2024/11/03 19:57:33 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int count_lines(char *file_name)
{
    int     fd;
    int     line_count;
    char    *line;
    
    fd = open (file_name, O_RDONLY);
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

int check_width_map(char *file_name)
{ 
    int     fd;
    char    *read_line;
    size_t  width;
    size_t  len;
    int     error;
    
    fd = open (file_name, O_RDONLY);
    if (fd < 0)
        return(1);
    error = 0;
    read_line = get_next_line(fd);
    width = ft_strlen(read_line);
    if (ft_strchr(read_line, '\n') != NULL)
        width--;
    while (read_line != NULL)
    {
        len = ft_strlen(read_line);
        if (ft_strchr(read_line, '\n') != NULL)
            len--;
        if (len != width)
            error = 1;
        free(read_line);
        read_line = get_next_line(fd);
    }
    close(fd);
    return(error);
}

int check_valid_char_map(char *file_name)
{
    int     fd;
    int     error;
    size_t  j;
    char    *str;
    
    fd = open (file_name, O_RDONLY);
    if (fd < 0)
        return(1);  
    error = 0;
    str = get_next_line(fd);
    while (str != NULL)
    {
        j = 0;
        while(j < ft_strlen(str))
        {
            if (str[j] != '1' 
                && str[j] != '0'
                && str[j] != 'E'
                && str[j] != 'C'
                && str[j] != 'P' 
                && str[j] != '\n')
                  error = 1;
                j++;
        }
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return(error);
}

int main(int argc, char **argv)
{   
    int     fd;
    int     i;
    size_t  line_count;
    char    *line;
    char    **map;
    char    *confirm;
    int      check;
    
    if (argc != 2)
        return(ft_printf("Bad list of arguments\n"));
    confirm = ft_strrchr(argv[1], '.');
    check = ft_strncmp(confirm, ".ber", ft_strlen(confirm));
    if (check != 0)
        return(ft_printf("bad file extension (%s)\n", confirm));   
    fd = open (argv[1], O_RDONLY);
    if (fd < 0)
        return(ft_printf("Could not open file!\n"));
    line_count = count_lines(argv[1]);
    if (check_width_map(argv[1]) == 1)
        return(ft_printf("This map is not rectangular!\n"));
    if (check_valid_char_map(argv[1]) == 1)
        return(ft_printf("This is a invalid map!\n"));
    map = ft_calloc(line_count, sizeof(char*));
    if (!map)
        return(ft_printf("Failed allocating memory for map!\n"));
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
