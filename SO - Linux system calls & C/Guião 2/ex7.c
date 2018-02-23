#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <time.h>

/*
INPUT A DAR: ./ex6 250 1000 25
Vai procurar pelo número 25 na matriz aleatória 250x1000
Imprime as linhas (ordenadas) onde encontra o 25 para o ficheiro matriz.txt
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {

        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


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
    int linhasFound[rows];

    int status;
    int exitstatus;
    int j = 0;


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
					_exit(k);
				}
			}

            _exit(0);
		}

		else {
            // espera pelo fim do filho
            waitpid(childId, &status, 0);

            // retorna o exit status do filho
            exitstatus = WEXITSTATUS(status);
            if (exitstatus > 0) {
                linhasFound[j] = exitstatus;
                j++;
            }
	    }
    }

    int linhaAordenar;
    j = 0;

    int fdfile;
    remove("matriz.txt");
    fdfile = creat("matriz.txt", 0777);

    while (j < rows) {

        linhaAordenar = linhasFound[j];
        quickSort(array[linhaAordenar], 0, columns);

        char linha[10];
        sprintf(linha, "Linha %d: ", linhaAordenar);
        write(fdfile, linha, strlen(linha));

        for (int i = 0; i < columns; i++) {
            char numeros[100];
            sprintf(numeros, "%d ", array[linhaAordenar][i]);
            write(fdfile, numeros, sizeof(int));
        }

        write(fdfile, "\n", 1);

        j++;
    }

    close(fdfile);

    tFim = clock();
    tempoGasto = (tFim - tInicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("O programa demorou %g ms. \n", tempoGasto);

	return 0;
}
