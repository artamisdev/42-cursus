/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacampos <tacampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:50 by tacampos          #+#    #+#             */
/*   Updated: 2024/11/07 17:18:12 by tacampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	count_lines(char *file_name)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// ft_printf("\n%d",line_count);
	return (line_count);
}

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
				++counter;
			i++;
		}
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (counter < 1);
}

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
        if (read_line[0] != '1')
            ++error;
        if (read_line[ft_strlen(read_line) - 2] != '1')
            ++error;
        free(read_line);
        read_line = get_next_line(fd);
    };
    close(fd);
    return(error);
};

//int check_upper_and_lower_walls(char *file_name){};

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	size_t	line_count;
	char	*line;
	char	**map;
	char	*confirm;
	int		check;

	if (argc != 2)
		return (ft_printf("Bad list of arguments\n"));
	confirm = ft_strrchr(argv[1], '.');
	check = ft_strncmp(confirm, ".ber", ft_strlen(confirm));
	if (check != 0)
		return (ft_printf("Bad file extension (%s)\n", confirm));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Could not open file!\n"));
	line_count = count_lines(argv[1]);

    if (check_the_side_walls(argv[1]) != 0)
        return(ft_printf("The walls of this map are not valid!\n"));
        
    if (check_width_map(argv[1]) == 1)
		return (ft_printf("This map is not rectangular!\n"));
        
    if (check_collectibles(argv[1]) == 1)
		return (ft_printf("This map doesn't have enough collectibles!\n")); 
        
	if (check_player_map(argv[1]) == 1)
		return (ft_printf("This map have two players! It's forbbiden!\n"));
        
    if (check_exit_map(argv[1]) == 1)
		return (ft_printf("This map have two exits! It's forbbiden!\n"));
        
	if (check_valid_char_map(argv[1]) == 1)
        return (ft_printf("This is a invalid map!\n"));
        
	map = ft_calloc(line_count, sizeof(char *));
	if (!map)
		return (ft_printf("Failed allocating memory for map!\n"));
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
	return (0);
}
