#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;
    char *line;
    fd = open("teste.txt", O_RDONLY);

    line = get_next_line(fd);
    printf("<%s>", line);
    line = get_next_line(fd);
    printf("<%s>", line);
    line = get_next_line(fd);
    printf("<%s>", line);
    line = get_next_line(fd);
    printf("<%s>", line);

}
// int main()
// {
//     int fd;
//     char *buf;
//     int buf_size = 5;
//     int i;

//     i = 0;
//     buf = malloc((buf_size + 1) * sizeof(char));
//     buf[buf_size] = '\0'; 
//     fd = open("teste.txt", O_RDONLY);
//     while (i < 3)
//     {
//         read(fd, buf, buf_size);
//         printf("\"%s\"\n", buf);
//         i++;
//     }
//     free(buf);
//     close(fd);
// }
