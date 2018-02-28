#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct slist *LInt;
typedef struct slist {
    int valor;
    LInt prox;
} Nodo;

// acrescenta
LInt cons (LInt l, int x) {

    LInt head;

    head = malloc (sizeof(struct slist));
    head->valor = x;
    head->prox = l;

    return head;

}

LInt tail (LInt l) {

    LInt tmp;
    tmp = l->prox;

    free(l);

    return tmp;

}

void init (LInt l) {

    while(l) {
        l = l->prox;
    }

    free(l);

    return;

}

LInt snoc (LInt l, int x) {

    LInt new;
    new = malloc (sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;

    while(l -> prox != NULL) {

        l = l->prox;
    }

    l->prox = new;

    return new;

}

LInt concat (LInt a, LInt b) {

    LInt tmp = a;

    while (a -> prox != NULL) {

        a = a->prox;

    }

    a->prox = b;

    return tmp;

}


// só pra n termos de percorrer tudo só pra chegar ao
// ultimo elemento

typedef struct difl {
    LInt inicio, fim;
} DifList;

// adicionar ao fim
DifList snocAl (DifList l, int x) {

    LInt new;
    new = malloc (sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;

    l.fim->prox = new;
    l.fim = new;

    return l;

}

DifList concatAl (DifList a, DifList b) {

    a.fim->prox = b.inicio;
    a.fim = b.fim;

    return a;

}

typedef struct alunos *Aluno;
typedef struct alunos {

    char nome[60];
    int numero;
    int nota;
    Aluno prox;

} NodoAluno;


// acrescentaAluno, procura e aprovados

Aluno acrescentaAluno (char nome[], int numero, int nota) {

    Aluno aluno = malloc (sizeof(struct alunos));

    strcpy(aluno->nome, nome);
    aluno->numero = numero;
    aluno->nota = nota;
    aluno->prox = NULL;

    return aluno;

}

int procura (Aluno t, int numero) {

    while (t->prox != NULL) {

        if (t->numero == numero) return 1;
        t = t->prox;
    }

    return 0;
}

int aprovacao (Aluno t) {

    int contador = 0;

    while (t->prox != NULL) {

        if (t->nota >= 9.5) contador++;
    }

    return contador;

}

int main() {

    LInt l;
    cons(l, 4);
    // tail(l);
    return 0;

}
