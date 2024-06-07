#include "get_next_line.h"

static  char *catch_line(char *str)
{
    int     i;
    char    *line;

    i = 0;
    if (!str || str[0] == '\0')
        return (NULL);
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    line = ft_calloc(sizeof(char), i + 2);
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] != '\n' && str[i] != '\0')
    {
        line[i] = str[i];
        ++i;
    }
    if (str[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

static char    *get_line_from_buffer(char *buffer, char *line)
{ 
    char    *aux;
    char    *post_nl;
    int     len;
    char    *free_catch;

    free_catch = catch_line(buffer);
    post_nl = ft_strchr(buffer, '\n');
    if(post_nl == NULL)
    {
        aux = line;
        line = ft_strjoin(line, buffer);
        free(aux);
        if (!line)
            return(NULL);
    }
    else
    {
        len = ft_strlen(post_nl + 1);
        aux = line;
        line = ft_strjoin(line, free_catch);
        free(free_catch);
        free(aux);
        if (!line)
            return(NULL);
        ft_memmove(buffer, post_nl + 1, len);
        buffer[len] = '\0';
    }
    return(line);

}
static int    initialize(char **buffer, char **line)
{
    if (*buffer == NULL)
    {
        *buffer = ft_calloc(sizeof(char) ,(BUFFER_SIZE + 1));
        if (!*buffer)
            return(0);
    }
    *line = ft_calloc(sizeof(char), 1);
    if (!*line)
    {
        free(buffer);
        return(0);
    }
    *line[0] = '\0';
    return(1);
}
char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    int  chars_read;

    if (fd < 0 || BUFFER_SIZE < 1)
        return(NULL);
    if (read(fd, buffer, 0) < 0)
        return(NULL);
    if (!initialize(&buffer, &line))
        return(NULL);
    if (buffer != NULL && buffer[0] != '\0')
    {
        line = get_line_from_buffer(buffer, line);
        if(!line){
            free(buffer);
            buffer = NULL;
            return(NULL);
        }
        if (ft_strchr(line, '\n'))
            return(line);
    }
    while((chars_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[chars_read] = '\0';
        line = get_line_from_buffer(buffer, line);
        if (!line)
        {
            free(buffer);
            buffer = NULL;
            return(NULL);
        }
        if (ft_strchr(line, '\n'))
            return(line);
    }
    if (line[0] == '\0')
    {
        free(line);
        return(NULL);
    }
    free(buffer);
    buffer = NULL;
    return (line);
}
