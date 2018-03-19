#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <string.h>


/*
Imprime soma do número de linhas de ficheiro passado como argumento
*/

int main(int argc, char *argv[]){

    long bytesRead = 0;
    ssize_t i;
    char c;
    int linhas = 0;

    int fd = open(argv[1], O_RDONLY);

    do {

        i = read(fd, &c, 1);

        if (c == '\n') linhas++;

    } while (i > 0);

    printf("%d", linhas);
    return linhas;
}
