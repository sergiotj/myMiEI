
#include <stdio.h>
#include <time.h>

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

// insere x num vetor ordenado
// temos de mover o array para a frente começando pelo fim
void insere(int v[], int N, int x) {

    while (N > 0 && v[N-1] > x) {

        v[N] = v[N-1];
        N--;
    }

    v[N] = x;

}

void iSort(int v[], int N) {
    int i;

    for (i = 1; i < N; i++) {
        insere(v, i, v[i]);
    }
}


// indice onde está o maior elemento
int maxInd (int v[], int N) {

    int maxInd;
    int max = 0;
    int i = 0;

    while (N > 0) {

        if (v[i] > max) {
            max = v[i];
            maxInd = i;
        }

        N--;
        i++;
    }

    return maxInd;

}

void sortInd(int v[], int N) {

    int maiorEl;
    int temp;

    while (N >= 0) {

        maiorEl = maxInd(v, N);

        temp = v[N-1];
        v[N-1] = v[maiorEl];
        v[maiorEl] = temp;

        N--;
    }

}

void swap(int v[], int xp, int yp) {

    int temp = v[xp];
    v[xp] = v[yp];
    v[yp] = temp;
}

// mete o maior elemento no fim
void bubble (int v[], int N) {

    int i;
    for (i = 1; i < N; i++) {

        if (v[i-1] > v[i]) {
            swap(v, i-1, i);
        }
    }
}

void bubbleSort(int v[], int N) {

    int maiorEl;
    int temp;

    while (N >= 0) {

        bubble(v, N);
        N--;
    }

}




int main() {

    int v[] = {1,2,3,4,6,8,5,86,56,33,59,49};

    // insere(v, 3, 2);

    int N = 0;

    while (N < 12) {

        printf("%d ", v[N]);
        N++;
    }
    printf("\nOrdenação!\n");

    iSort(v, 12);

    N = 0;

    while (N < 12) {

        printf("%d ", v[N]);
        N++;
    }

    /////////////////

    printf("\nOrdenação com ind!\n");

    bubbleSort(v, 12);

    N = 0;

    while (N < 12) {

        printf("%d ", v[N]);
        N++;
    }



}
