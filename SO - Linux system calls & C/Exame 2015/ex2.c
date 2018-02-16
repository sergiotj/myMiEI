#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <string.h>


int main(int argc, char *argv[]){

    int fd[2];
    int status;
    pid_t child;
    int bytesRead = 1;
    char buffer[25];

    char *op1 = NULL;
    char *operator = NULL;
    char *op2 = NULL;
    char *resultado = NULL;
    size_t len = 0;

    pipe(fd);

    getline(&op1, &len, stdin);
    getline(&operator, &len, stdin);
    getline(&op2, &len, stdin);
    getline(&resultado, &len, stdin);

    
    child = fork();
    if (child == 0) {

        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);

        execl("calculator.exe","calculator.exe",op1,operator,op2,NULL);

    }

    else {
        
        wait(&child);
        close(fd[1]);

        char fim[500];
        int bytesReadFinal;
        bytesReadFinal = read(fd[0], fim, 500);

        if (strcmp(resultado, fim) == 0) {
            printf("O resultado é o esperado!");
        }

        else {
            kill(child, SIGKILL);
            kill(getpid(),SIGKILL);
        }

        write(1, fim, bytesReadFinal);

    }

    return 0;
}

