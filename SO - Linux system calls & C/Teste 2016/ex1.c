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

	int nPipes = argc-1;
    int fd[nPipes][2];
    int status;
    pid_t pids[argc-1];
    time_t tempos[argc-1];
    time_t end;

    for (int i = 0; i < argc; i++) {

        pipe(fd[i]);

        pids[i] = fork();

        // tenho de passar o argv[2] ao filtro

        if (pids[i] == 0) {

            close(fd[i][0]);
            dup2(fd[i][1], 1);
            close(fd[i][1]);

            execl("pProgram.exe","pProgram.exe",NULL);
            exit(0);

        }

        tempos[i] = time(NULL);
    }

    int ativos = argc-1;
    double elapsed;

    printf("processos ativos: %d\n", argc-1);

    while (1) {
	    for (int i = 0; i < argc; i++) {

            close(fd[i][1]);

            char buffer[i][3];

            int bytesRead = read(fd[i][0], buffer[i], 3);

            if (bytesRead == 0 && pids[i] > 0) {

            	kill(pids[i], SIGTERM);
    	        end = time(NULL);
        		elapsed = difftime(end, tempos[i]);

            	printf("Matou o processo com o pid %d. Esteve %Lf ms ativo.\n", pids[i], (long double) elapsed);
            	pids[i] = 0;
            	ativos--;

            	if (ativos == 0) goto end;
            }

            write(1, buffer[i], bytesRead);

	    	if (i == argc-1) i = 0;
		}

	}

	end:
	printf("processos ativos: %d\n", ativos);
	printf("O programa terminou porque não há mais nenhum processo a mandar OKs.\n");
    return 0;
}

