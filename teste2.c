#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <string.h>


ssize_t readLine(int fd, char* buffer, long maxBytes) {

    long bytesRead = 0;
    ssize_t i;
    char c;

    int lines = 0;

    do {

        i = read(fd, &c, 1);

        if (i > 0) {
            buffer[bytesRead] = c;
            bytesRead++;

        }

    } while (i > 0 && bytesRead < maxBytes && c != 'a');

    buffer[bytesRead] = '\0';

    // Devolver o numero de bytes lidos
    return bytesRead;
}


int main(int argc, char *argv[]){

	// um processo deve executar filtro e outro processo deve executar existe.
	// é recebido como argumento o número de pares de pipes a executar ao mesmo tempo

	int nPipes = atoi(argv[1]);
    int fd[nPipes+1][2];
    int status;
    char buffer[500];
    int bytesRead = 1;
    pid_t childId;

    for (int i = 1; i < atoi(argv[1])+1; i++) {

        pipe(fd[i]);
        childId = fork();

        // tenho de passar o argv[2] ao filtro

        if (childId == 0) {

            close(fd[i][0]);
            dup2(fd[i][1], 1);
            close(fd[i][1]);

            execl("filtro.exe","filtro.exe",argv[2],NULL);
            exit(0);
        }
/*
        childId = fork();

        // tenho de passar o output do filtro ao existe

        if (childId == 0) {

            dup2(0, fd[i][0]);
            close(0);
            dup2(fd[i][1], 1);
            close(fd[i][1]);

            execl("existe","existe",argv[2],NULL);
            exit(0);
        }
*/
        else {

            sleep(1);

            while (wait(&status) > 0) {
                printf("Um filho terminou com exitstatus %d\n", status);

            }

            close(fd[i][1]);

            bytesRead = read(fd[i][0], buffer, 1000);

            write(1, buffer, bytesRead);

        }
        
    }

    return 0;
}

