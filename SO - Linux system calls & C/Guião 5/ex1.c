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
int pipe(pd[2]);
*/

// redirecionar error e output para ficheiros saida.txt e erros.txt
int main(int argc, char *argv[]) {

    int fd[2];
    pipe(fd);

    char teste[] = "Teste para o exercício 1";
    sleep(1);

    write(fd[1], teste, strlen(teste));
    close(fd[1]);

    pid_t child;
    child = fork();

    if (child == 0) {

        close(fd[1]);
        char buffer[500];

        read(fd[0], buffer, strlen(teste));
        close(fd[0]);

        // filho lê do pai e escreve.
        write(1, buffer, strlen(buffer));
        exit(0);

    }

    else wait(0);

    return 0;

}
