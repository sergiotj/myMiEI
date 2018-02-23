#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

/*
INPUT A DAR: ./ex6 250 1000 25
Vai procurar pelo número 25 na matriz aleatória 250x1000
*/


int main(int argc, char const *argv[]){

	clock_t tInicio, tFim;
	double tempoGasto;
	tInicio = clock();

	int numberToFind = atoi(argv[3]);
	int rows = atoi(argv[1]);
	int columns = atoi(argv[2]);

	printf("Procurando pelo número %d na matriz %dx%d.\n", numberToFind, rows, columns);

	srand(time(NULL));
	int array[rows][columns];
	int total = 0;
	int status;
	int exitstatus;


	// Criar matriz aleatória
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			array[i][j] = rand() % 101;
		}
	}

	// Procurar pelo número na matriz aleatória

	pid_t childId;

	for (int k = 0; k < rows; k++) {

		childId = fork();

		if (childId == 0) {
			for (int l = 0; l < columns; l++) {
				if (array[k][l] == numberToFind) {
					_exit(1);
				}
			}

            _exit(0);
		}

		else {
            // espera pelo fim do filho
            waitpid(childId, &status, 0);

            // retorna o exit status do filho
            exitstatus = WEXITSTATUS(status);
            if (exitstatus == 1) {
				total++;
            }
	    }
    }



    tFim = clock();
    tempoGasto = (tFim - tInicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("O número %d foi encontrado %d vezes. \n", numberToFind, total);
    printf("O programa demorou %g ms. \n", tempoGasto);

	return 0;
}
