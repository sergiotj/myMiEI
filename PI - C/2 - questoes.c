int length (LInt l){

    int contador = 0;

    while (l) {

        contador++;
        l = l->prox;
    }

    return contador;
}


int removeOneOrd (LInt *l, int x){

    while (*l) {

        if ((*l)->valor == x) {

            LInt next = (*l)->prox;
            free(*l);
            *l = next;

            return 0;
        }

    l = &((*l)->prox);

    }

    return 1;
}

void appendL (LInt *l, int x){

    LInt atual = *l;
    LInt novo = newLInt(x, NULL);

    if (*l == NULL) {
        *l = novo;
        return;
    }

    while (atual->prox) {

        atual = atual->prox;
    }

    atual->prox = novo;
}

LInt arrayToList (int v[], int N){

    LInt novo;
    LInt last = NULL;
    if (N == 0) return last;

    N--;
    while (N >= 0) {
        novo = newLInt(v[N], last);
        last = novo;
        N--;
    }

    return novo;
}

LInt somasAcL (LInt l) {

    LInt toda = l;
    LInt inicio = NULL;
    LInt novo;
    int n = 0;

    if (l == NULL) return inicio;

    LInt head = newLInt(somaListaAte(&toda, n), NULL);
    inicio = head;
    n++;

    while (l->prox) {

        novo = newLInt(somaListaAte(&toda, n), NULL);
        head->prox = novo;
        head = novo;
        l = l->prox;
        n++;
    }

    return inicio;
}

int somaListaAte(LInt *l, int n) {

    LInt atual = *l;

    int soma = 0;

    while (n >= 0 && atual) {

        soma += atual->valor;
        atual = atual->prox;
        n--;
    }

    return soma;

}

int listToArray (LInt l, int v[], int N){

    int contador = 0;

    if (l == NULL) return 0;

    while (l && N > 0) {

        v[contador] = l->valor;
        contador++;
        l = l->prox;
        N--;
    }

    return contador;
}

int removeMaiorL (LInt *l){

    if (*l == NULL) return 0;

    LInt atual = *l;
    int maior = 0;
    int flag = 0;

    while (atual) {

        if (atual->valor > maior) maior = atual->valor;
        atual = atual->prox;

    }

    atual = *l;

    while (atual) {

        if (atual->valor == maior) {
            free(*l);
            *l = atual->prox;
            return maior;
        }

        atual = atual->prox;
        l = &((*l)->prox);

    }

}

int removeAll (LInt *l, int x){

    LInt atual = *l;
    int contador = 0;

    while (atual) {

        if (atual->valor == x) {

            contador++;
            free(*l);
            *l = atual->prox;
            atual = atual->prox;

        }

        else {

            atual = atual->prox;
            l = &((*l)->prox);
        }

    }

    return contador;

}

int maximo (LInt l){

    int maior = 0;
    while (l) {

        if (l->valor > maior) maior = l->valor;
        l = l->prox;
    }

    return maior;
}

int drop (int n, LInt *l){

    LInt atual = *l;

    if (*l == NULL) return 0;
    int contador = 0;

    while (n > 0 && atual) {

        contador++;
        n--;
        free(*l);
        *l = atual->prox;
        atual = atual->prox;

    }

    return contador;

}

LInt NForward (LInt l, int N){

    LInt atual = l;

    while (atual && N > 0) {

        atual = atual->prox;
        N--;

    }

    return atual;
}

int take (int n, LInt *l){

    LInt atual = *l;
    int contador = 0;

    while (n > 0 && atual) {

        atual = atual->prox;
        l = &((*l)->prox);
        n--;
        contador++;
    }

    free(*l);
    *l = NULL;

    return contador;
}

LInt reverseL (LInt l){
    LInt atual = l;
    LInt prev = NULL;
    LInt next = NULL;

    while (atual) {

         next = atual->prox;
         atual->prox = prev;
         prev = atual;
         atual = next;
    }

    return prev;
}

void insertOrd (LInt *l, int x){

    LInt atual = *l;

    while (atual && x >= atual->valor) {

        atual = atual->prox;
        l = &((*l)->prox);
    }

    LInt toInsert = newLInt(x, atual);
    (*l) = toInsert;

}

void init (LInt *l){

    LInt atual = *l;

    while (atual->prox) {

        l = &((*l)->prox);
        atual = atual->prox;

    }

    free(*l);
    *l = NULL;

}

LInt rotateL (LInt l){

    if (l == NULL || l->prox == NULL) return l;

    LInt toReturn = l->prox;
    LInt start = toReturn;

    LInt head = l;
    head->prox = NULL;

    while (toReturn->prox) {

        toReturn = toReturn->prox;
    }

    toReturn->prox = head;

    return start;

}


//////////////// ARVORES

int altura (ABin a){

    int alt = 0;
    if (!a) return 0;

    if (a) {

        alt = 1 + max(altura(a->esq),altura(a->dir));
    }

    return alt;
}

ABin cloneAB (ABin a) {

    ABin nova = NULL;

    if (a) {

        nova = newABin(a->valor, cloneAB(a->esq), cloneAB(a->dir));
    }

    return nova;

}
