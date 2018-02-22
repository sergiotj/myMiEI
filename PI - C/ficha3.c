
#include <stdio.h>
#include <ctype.h>

#define N 10

/*
calcula a soma dos elementos de um array
*/

int soma (int v[], int number) {

    int i = 0;
    int soma = 0;

    while (number > 0) {

        soma += v[i];
        number--; i++;
    }

    return soma;

}

/*
calcula o maior dos elementos de um array
*/
int maximum (int v[], int number) {

    int maximo = 0;
    int i = 0;

    while (number > 0) {

        if (v[i] > maximo) maximo = v[i];

        number--; i++;
    }

    return maximo;

}

/*
preenche o array com os quadrados dos primeiros N numeros naturais
*/
void quadrados (int q[], int number) {

    int i = 0;

    while (number > 0) {

        q[i] = i*i;
        i++; number--;

    }

    return 0;

}

/*
calcula quantas vogais tem uma string
*/
int contaV (char s[]) {

    int contador = 0;
    int i = 0;

    while (s[i] != '\0') {

        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
        || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {

            contador++;
        }

        i++;

    }

    return contador;

}

/*
calcula quantas palavras tem uma string
Assuma que uma palavra é um conjunto de caracteres nao brancos terminada por um caracter
branco. Use para isso a funçao standard (ctype.h) int isspace(int c)
*/
int contaPal (char s[]) {

    int i = 0;
    int palavras = 0;

    while (s[i] != '\0') {

        if (isspace(s[i+1])) palavras++;
        i++;
    }

    return palavras;
}

int main() {

    int x[10] = {1, 2, 3, 4, 5, 20, 7, 8, 9, 10};

    printf("A soma do array é %d.\n", soma(x, N));
    printf("O máximo valor do array é %d.\n", maximum(x, N));

    int aquadrado[10];
    quadrados(aquadrado, N);

    char myName[] = "Sergio";
    printf("O teu nome tem %d vogais.\n", contaV(myName));

    char frase[] = "Ola caraças isto é que foi um dia de trabalho ";
    printf("A frase tem %d palavras.\n", contaPal(frase));

    return 0;


}
