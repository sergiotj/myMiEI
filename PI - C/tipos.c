
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct stack {
    int sp;
    int valores[MAX];
} STACK;


void initStack (STACK *s) {

    s->sp = 0;

}


int isEmptyS (STACK *s) {

    if (s->sp > 0) return 0;

    return 1;
}

int push (STACK *s, int x) {

    int indice = s->sp;

    if (indice == MAX) return 1;

    s->valores[indice] = x;
    return 0;

}

int pop (STACK *s, int *x) {

    int indice = s->sp;

    if (indice <= 0) return 1;

    *x = s->valores[indice--];
    return 0;

}

int top (STACK *s, int *x) {

    int indice = s->sp;
    if (indice == 0) return 1;

    *x = s->valores[0];
    return 0;
}

typedef struct queue {
    int inicio, tamanho;
    int valores [MAX];
} QUEUE;

void initQueue (QUEUE *q) {

    q->inicio = 0;
    q->tamanho = 0;
}


int isEmptyQ (QUEUE *q) {

    int size = q->tamanho;

    if (size == 0) return 1;

    return 0;

}

// retorna 0 se sucesso, mete o x na queue
int enqueue (QUEUE *q, int x) {

    int size = q->tamanho;

    if (size < MAX) {
        q->valores[size--] = x;
        q->tamanho = q->tamanho + 1;
    }

    else return 1;

    return 0;

}


int dequeue (QUEUE *q, int *x) {

    int size = q->tamanho;

    if (isEmptyQ(q) != 1) {

        int inicio = q->inicio;

        *x = q->valores[inicio];


        int i = 0;
        while(i < size) {
            q->valores[i] = q->valores[i+1];
        }

        q->tamanho = q->tamanho - 1;

    }

    else return 1;

    return 0;

}


int front (QUEUE *q, int *x) {

    if (isEmptyQ(q) != 1) {

        int inicio = q->inicio;

        *x = q->valores[inicio];
        q->tamanho = q->tamanho - 1;
    }

    else return 1;

    return 0;

}

/*
Para gerir a informacao sobre os alunos inscritos a uma dada disciplina, e necessario armazenar os seguintes dados:
• Nome do aluno (string com no maximo 60 caracteres) • Nu´mero do aluno • Nota
*/

typedef struct aluno {
    char nome[60];
    int numero;
    int nota;
} Aluno;

typedef struct turma {

    Aluno alunos[100];
    int tamanho;

} Turma;

void initTurma(Turma *t) {

    t->tamanho = 0;

    return;
}

int acrescentaAluno (Turma *t, Aluno a) {

    int size = t->tamanho;

    if (size == 100) return 1;

    t->alunos[size] = a;
    t->tamanho = t->tamanho + 1;

    return 0;

}

int procura (Turma *t, int numero) {

    int i = 0;
    int size = t->tamanho;

    while (i < size) {

        if (t->alunos[i].numero == numero) return i;
        i++;
    }

    return -1;

}

int aprovacao (Turma *t) {

    int contador = 0;
    int size = t->tamanho;
    int i = 0;

    while (i < size) {

        if (t->alunos[i].nota >= 9.5) contador++;
        i++;
    }

    return contador;

}

int main() {

    STACK s;
    initStack(&s);
    push(&s, 24);

    int valor = s.valores[0];
    printf("o valor lá é %d\n", valor);


    Turma t;
    initTurma(&t);

    Aluno a1;
    strcpy(a1.nome, "Sérgio");
    a1.numero = 77730;
    a1.nota = 10;

    acrescentaAluno(&t, a1);

    printf("Alunos com aprovacao: %d\n", aprovacao(&t));


    return 0;
}
