#include "get_next_line.h"

// para leer

// que te agarre hasta el salto de linea

// statica 


char *get_next_line(int fd)
{
    char    buffer[5];
    char    line[100];
    char    *rest;


    if (fd < 0)
        return(NULL);
    while (read(fd, buffer, BUFFER_SIZE) > 0)
    {
        rest = ft_strchr(buffer, '\n');
        if(rest == NULL)
        {
            line = ft_strjoin(line, buffer);         
        }
        else
        {
            // aqui separo o buffer em duas partes, antes e depois do \n.

        }

       
    }

}


/*int main()
{
    int fd;
    char *buf;
    int buf_size = 5;
    int i;

    i = 0;
    buf = malloc((buf_size + 1) * sizeof(char));
    buf[buf_size] = '\0'; 
    fd = open("teste.txt", O_RDONLY);
    while (i < 3)
    {
        read(fd, buf, buf_size);
        printf("\"%s\"\n", buf);
        i++;
    }
    free(buf);
    close(fd);
}*/

/*
{
    int fd; // variável chamada "fd" que usaremos para representar o arquivo.
    char *buf; // variável chamada "buf" que usaremos para armazenar os dados lidos do arquivo.
    int buf_size = 44; // Aqui estamos definindo o tamanho inicial do buffer como 1.
    buf = malloc((buf_size + 1) * sizeof(char)); // Aqui alocamos memória para o buffer armazenar buf_size caracteres, mais um para o caractere nulo.
    buf[buf_size] = '\0'; // definindo o último caractere do buffer como nulo, para garantir que seja uma string válida.
    fd = open("teste.txt", O_RDONLY); // abrindo o arquivo "teste.txt" no modo de leitura apenas (O_RDONLY) e armazenando o descritor de arquivo na variável "fd".
    read(fd, buf, buf_size); // lendo dados do arquivo aberto (fd) e armazenando no buffer (buf), lendo até buf_size caracteres.
    printf("\"%s\"\n", buf); // imprime na tela o conteúdo do buffer, entre aspas duplas.
    free(buf); // liberando a memória alocada para o buffer, para evitar vazamentos de memória(leaks de memória).
    close(fd); // fechamos o arquivo que foi aberto, para liberar recursos do sistema operacional.
}
*/