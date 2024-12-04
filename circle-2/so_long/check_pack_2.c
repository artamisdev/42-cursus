/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:22:57 by tacampos          #+#    #+#             */
/*   Updated: 2024/12/04 15:24:12 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_the_side_walls(char *file_name)
{
    int		fd;
	char	*read_line;
    int     error;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
    read_line = get_next_line(fd);
    error = 0;
    while(read_line != NULL)
    {
        if (read_line[ft_strlen(read_line) - 1] == '\n')
            read_line[ft_strlen(read_line) - 1] = '\0';
        if (read_line[0] != '1')
            error++;
        if (read_line[ft_strlen(read_line) - 1] != '1')
            error++;
        free(read_line);
        read_line = get_next_line(fd);
    };
    close(fd);
    return(error);
}

int check_char_one(char *read_line)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	if (read_line[ft_strlen(read_line) - 1] == '\n')
		read_line[ft_strlen(read_line) - 1] = '\0';
	while (read_line[i])
	{
		if (read_line[i] != '1')
			error++;
		i++;
	}
	
	return(error);
}
int check_lower_wall(char *file_name)
{
	int		fd;
	int		error;
	char	*next_line;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	error = 0;
	read_line = get_next_line(fd);
	while (read_line != NULL)
	{
		next_line = get_next_line(fd);
		if (next_line != NULL)
		{
			free(read_line);
			read_line = next_line;
			continue ;
		}
		error = check_char_one(read_line);
		free(read_line);
		read_line = NULL;
	}
	close(fd);
	return (error);	
}

int check_upper_wall(char *file_name)
{
	int		fd;
	int		error;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
	error = check_char_one(read_line);
	free(read_line);
	close(fd);
	return(error);
}
