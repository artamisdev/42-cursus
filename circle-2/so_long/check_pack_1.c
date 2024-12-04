/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:14:25 by tacampos          #+#    #+#             */
/*   Updated: 2024/12/04 15:17:22 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_width_map(char *file_name)
{
	int		fd;
	char	*read_line;
	size_t	width;
	size_t	len;
	int		error;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
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
	return (error);
}

int	check_valid_char_map(char *file_name)
{
	int		fd;
	int		error;
	size_t	j;
	char	*str;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	error = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		j = 0;
		while (j < ft_strlen(str))
		{
			if (str[j] != '1' && str[j] != '0' && str[j] != 'E' && str[j] != 'C'
				&& str[j] != 'P' && str[j] != '\n')
				error = 1;
			j++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (error);
}

int	check_exit_map(char *file_name)
{
	int		fd;
	size_t	i;
	int		counter_e;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
	counter_e = 0;
	while (read_line != NULL)
	{
		i = 0;
		while (i < ft_strlen(read_line))
		{
			if (read_line[i] == 'E')
				++counter_e;
			i++;
		}
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (counter_e != 1 );
}
int	check_player_map(char *file_name)
{
	int		fd;
	size_t	i;
    int		counter_p;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
    counter_p = 0;
	while (read_line != NULL)
	{
		i = 0;
		while (i < ft_strlen(read_line))
		{
            if (read_line[i] == 'P')
				++counter_p;
			i++;
		}
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (counter_p != 1);
}

int	check_collectibles(char *file_name)
{
	int		fd;
	size_t	i;
    int		counter;
	char	*read_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	read_line = get_next_line(fd);
    counter = 0;
	while (read_line != NULL)
	{
		i = 0;
		while (i < ft_strlen(read_line))
		{
            if (read_line[i] == 'C')
				counter++;
			i++;
		}
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (counter < 1);
}