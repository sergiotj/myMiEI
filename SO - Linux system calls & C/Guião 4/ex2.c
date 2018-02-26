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
int dup(int fd);
int dup2(int fd1, int fd2);
*/

// redirecionar error e output para ficheiros saida.txt e erros.txt
int main(int argc, char *argv[]) {

    int fdIn = open("etc/passwd", O_RDONLY);

    int fdOut = open("saida.txt", O_WRONLY | S_IRUSR | S_IWUSR);

    int fdError = open("erros.txt", O_WRONLY | S_IRUSR | S_IWUSR);

    // redirecionar
    dup2(fdIn, 0);
    dup2(fdOut, 1);
    dup2(fdError, 2);

    close(fdIn);
    close(fdOut);
    close(fdError);

    char buffer[500];

    while (read(0, buffer, 50) > 0) {

        write(1, buffer, strlen(buffer));
        write(2, buffer, strlen(buffer));

    }

    char bufferT[] = "Filho: ";
    strcat(bufferT, buffer);

    pid_t child;

    child = fork();

    if (child == 0) {

        write(1, bufferT, strlen(bufferT));
        write(2, bufferT, strlen(bufferT));

    }

    else wait(0);

    return 0;

}
