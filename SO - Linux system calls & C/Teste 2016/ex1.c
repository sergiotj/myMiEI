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

	// um processo deve executar filtro e outro processo deve executar existe.
	// é recebido como argumento o número de pares de pipes a executar ao mesmo tempo

	int nPipes = argc;
    int fd[nPipes][2];
    int status;
    pid_t pids[argc];

    for (int i = 0; i < argc-1; i++) {

        pipe(fd[i]);
        pid_t child = fork();

        pids[i] = child;

        // tenho de passar o argv[2] ao filtro

        if (child == 0) {

            close(fd[i][0]);
            dup2(fd[i][1], 1);
            close(fd[i][1]);

            execl("pProgram.exe","pProgram.exe",NULL);
            exit(0);

        }
    }

    int ativos = argc-1;

    printf("processos ativos: %d\n", strlen(pids));

    while (1) {
	    for (int i = 0; i < argc-1; i++) {

            close(fd[i][1]);

            char buffer[i][3];

            int bytesRead = read(fd[i][0], buffer[i], 3);

            if (bytesRead == 0 && pids[i] != 0) {

            	kill(pids[i], SIGTERM);
            	printf("Matou o processo com o pid %d\n", pids[i]);
            	pids[i] = 0;
            	ativos--;

            	if (ativos == 0) goto end;
            }

            write(1, buffer[i], bytesRead);

	    	if (i == argc-1) i = 0;
		}

	}

	end:
	printf("processos ativos: %d\n", strlen(pids));
	printf("O programa terminou porque não há mais nenhum processo a mandar OKs.\n");
    return 0;
}

