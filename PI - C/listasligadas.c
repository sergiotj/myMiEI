#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct slist *LInt;
typedef struct slist {
    int valor;
    LInt prox;
} Nodo;

// acrescenta
void cons (LInt *l, int x) {

     LInt head;

     head = malloc (sizeof(struct slist));
     head->valor = x;
     head->prox = *l;

     printf("passou\n");
     return;

 }


int main() {

    LInt l;

    cons(&l, 5);
    cons(&l, 10);
    cons(&l, 15);

    while(l != NULL) {
        printf("%d\n", l->valor);
        l = l->prox;
    }

}
