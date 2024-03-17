#include "get_next_line.h"

static  char *catch_line(char *str)
{
    int     i; //contador
    char    *line; // str que vai ser devolvida

    i = 0; // atribuindo valor inicial ao contador
    if (!str || str[0] == '\0')
        return (NULL); // condicinal se segurança
    while (str[i] != '\n' && str[i] != '\0')
        i++; // loop para saber a quantidade de char que deve ser alocado
    line = malloc(sizeof(char) * i + 2); // alocando memória e garantindo espaço para \n e \0
    if (!line)
        return (NULL); // condicional de segurança 
    i = 0; // reatribuindo valor, para iniciar do 0 novamente
    while (str[i] != '\n' && str[i] != '\0') // loop para caminhar por str
    {
        line[i] = str[i]; // copiando o valor de str à line
        i++;
    }
    if (str[i] == '\n') // condicional para add \n ao fnal de line
        line[i++] = '\n';  // caminhando para a proxima posiçao já atribuindo \n a posiçao atual
    line[i] = '\0'; // add \0 a posiçao final
    return (line); // retorna a linha pronta
}

// que te agarre hasta el salto de linea

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
            line = ft_strjoin(line, catch_line(buffer));
            // fazer uma funçao para um update do buffer (pos_nl)

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