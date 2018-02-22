
#include <stdio.h>
#include <time.h>

#define N 10
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)


// multiplicação de números
float multInt (int n, float m) {

    float resultado = 0;

    while (n > 0) {

        resultado += m;
        n--;

    }

    return resultado;


}

// processo mais eficiente de multiplicação de números
// vamos dividindo n por 2 e multiplicando m por 2
// o valor do produto é a soma dos n quando m é ímpar
float multIntOpcao (int n, float m) {

    float resultado = 0;

    while (n >= 1) {
        n = n/2;
        m = m*2;

        if (n%2 != 0) resultado += m;
    }

    return resultado;
}

int mdc (int a, int b) {

    int i = 1;
    int j = 0;
    int menorvalor;
    int maiorvalor;

    if (a > b) {
        menorvalor = b;
        maiorvalor = a;
    }

    else {
        menorvalor = a;
        maiorvalor = b;
    }

    int divisores[menorvalor];

    while (i <= menorvalor) {
        if (menorvalor%i == 0) {
            divisores[j] = i;
            j++;
        }
        i++;
    }

    j--;

    while (j > 0) {

        if (maiorvalor%divisores[j] == 0) return divisores[j];

        j--;
    }

    return 0;

}

// MDC por euclides
// o maior argumento passa a ser a diferença entre o maior e o menor
// testa sempre qual é o maior

int mdcOpcao(int a, int b) {

    while (a != 0 && b != 0) {

        if (a > b) {
            a = a - b;
        }

        else {
            b = b - a;
        }

    }

    if (a == 0) return b;
    if (b == 0) return a;

    return 0;

}

int mdcOpcao1(int a, int b) {

    while (a != 0 && b != 0) {

        if (a > b) {
            a = a % b;
        }

        else {
            b = b % a;
        }

    }

    if (a == 0) return b;
    if (b == 0) return a;

    return 0;

}

int fib (int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;
    else return (fib (n - 1) + fib (n-2));
}





int main() {

    float resultado;

    TICK(MultiIntA);
    resultado = multInt(11333444, 6944556);
    TOCK(MultiIntA);

    printf("O resultado é %.6f\n", resultado);

    TICK(MultiIntB);
    resultado = multIntOpcao(11333444, 6944556);
    TOCK(MultiIntB);


    printf("O resultado é %.6f\n", resultado);

    printf("O resultado do mdc é %d.\n", mdc(30,12));
    printf("O resultado do mdc de Euclides é %d.\n", mdcOpcao(30,12));
    printf("O resultado do mdc de Euclides1 é %d.\n", mdcOpcao1(30,12));

    printf("O resultado do fibo é %d.\n", fib(4));


}
