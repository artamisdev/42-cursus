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
        ++i;
    }
    if (str[i] == '\n') // condicional para add \n ao fnal de line
        line[i++] = '\n';  // caminhando para a proxima posiçao já atribuindo \n a posiçao atual
    line[i] = '\0'; // add \0 a posiçao final
    return (line); // retorna a linha pronta
}

static char    *get_line_from_buffer(char *buffer, char *line)
{ 
    char    *aux;
    char    *post_nl;
    int     len;

    post_nl = ft_strchr(buffer, '\n'); // aqui pego o final, o resto do que foi lido, depois de encontrar o \n
    if(post_nl == NULL) // se nao encontrei o \n, só sigo o loop jogando buffer em line
    {
        aux = line; // Ponteiro pra nao perder o line antigo
        line = ft_strjoin(line, buffer); // atribuindo o valor do novo line  
        free(aux); // liberando o ponteiro auxiliar       
    }
    else // encontrou um \n
    {
        len = ft_strlen(post_nl + 1); //defininho o tamanho de len
        aux = line;  // Ponteiro pra nao perder o line antigo
        line = ft_strjoin(line, catch_line(buffer)); // junto o final da linha com line
        free(aux); // liberando o ponteiro auxiliar 
        ft_memmove(buffer, post_nl + 1, len); // movimento o resto lido, pra dentro buffer, definindo como o inicio da proxima vez que for ler 
        buffer[len] = '\0'; // add o \0 ao final do buffer
    }
    return(line);

}
static int    initialize(char **buffer, char **line)
{
    *line = malloc(sizeof(char));
    if (!*line)
        return(0);
    *line[0] = '\0';
     if (*buffer == NULL)
    {
        *buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // buffer é um copo onde guardo cada parte lida, aqui aloco espaço de acordo com o BUFFER_SIZE
        if (!*buffer) // Condicional pra ver se deu certo o malloc
            return(0);
    }
    return(1);
}
char *get_next_line(int fd)
{
    static char    *buffer;
    char           *line;
    int            chars_read;

    if (fd < 0 || BUFFER_SIZE < 1 || !initialize(&buffer, &line)) // confirmo se o fd é valido e se o buffer size é maior que 1
        return(NULL);
    if(buffer[0]) // confere se a primeira letra do buffer é valida, ou seja se tem alguma coisa
       line = get_line_from_buffer(buffer, line);
    while ((chars_read = read(fd, buffer, BUFFER_SIZE)) > 0) // leio o arquivo aberto em fd, no tamanho de BUFFER_SIZE, pra dentro de buffer
    {
        buffer[chars_read] = '\0';
        line = get_line_from_buffer(buffer, line);
        if (ft_strchr(line, '\n') || chars_read < BUFFER_SIZE)
        {
            if (chars_read < BUFFER_SIZE)
                free(buffer);
            return(line);
        }
    }
    if (line[0] == '\0')
    {
        free(line);
        line = NULL;
    }
    return (line);
}
