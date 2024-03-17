#include "get_next_line.h"
#include <stdio.h>

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
        ++i;
    }
    if (str[i] == '\n') // condicional para add \n ao fnal de line
        line[i++] = '\n';  // caminhando para a proxima posiçao já atribuindo \n a posiçao atual
    line[i] = '\0'; // add \0 a posiçao final
    return (line); // retorna a linha pronta
}

// 

char *get_next_line(int fd)
{
    static char    *buffer;
    char           *line;
    char           *aux;
    char           *post_nl;
    int            len;

    line = malloc(sizeof(char));
    if (!line)
        return(NULL);
    line[0] = '\0';
    if (buffer == NULL)
    {
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // buffer é um copo onde guardo cada parte lida, aqui aloco espaço de cacordo com o BUFFER_SIZE
        if (!buffer) // Condicional pra ver se deu certo o malloc
            return(NULL);
        buffer[BUFFER_SIZE] = '\0'; // defino sempre o final de buffer como \0
    }
    if(buffer[0])
    {
        //???????????? - Proximo passo: resolver o caso do buffer com restinho. 
    }
    if (fd < 0) // confirmo se o fd é valido, ou seja se o arquivo foi aberto por open
        return(NULL);
    while (read(fd, buffer, BUFFER_SIZE) > 0) // leio o arquivo aberto em fd, no tamanho de BUFFER_SIZE, pra dentro de buffer
    {
        post_nl = ft_strchr(buffer, '\n'); // aqui pego o final, o resto do que foi lido, depois de encontrar o \n
        if(post_nl == NULL) // se nao encontrei o \n, só sigo o loop jogando buffer em line
        {
            aux = line;
            line = ft_strjoin(line, buffer);
            free(aux);         
        }
        else // encontrou um \n
        {
            len = ft_strlen(post_nl + 1);
            aux = line;
            line = ft_strjoin(line, catch_line(buffer)); // junto o final da linha com line
            free(aux);
            ft_memmove(buffer, post_nl + 1, len); // movimento o resto lido, pra dentro buffer, definindo como o inicio da proxima vez que for ler 
            buffer[len] = '\0';
            return(line);
        }
    }
    free(buffer); 
    return (line);
    
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

