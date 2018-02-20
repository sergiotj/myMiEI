
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int bitsUm (unsigned int n) {

    int num;
    int contador = 0;

    while(n != 0) {
        num = n%2;
        n = n/2;

        if (num == 1) contador++;
    }

    return contador;

}

int trailingZ (unsigned int n) {

    int num;
    int contador = 0;

    while(n != 0) {
        num = n%2;
        n = n/2;

        if (num == 0) contador++;
    }

    return contador;
}

int qDig (unsigned int n) {
    
    int num;
    int contador = 0;

    while(n != 0) {
        n = n/10;
        contador++;
    }

    return contador;
}

char *Mystrcat (char s1[], char s2[]) {
    int i = 0;

    while (s1[i] != '\0') {
        i++;
    }
    
    int j = 0;
    
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i++] = '\0';

    return s1;
}

char *Mystrcpy (char *dest, char source[]) {
    
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }

    dest[i++] = '\0';

    return dest;
}

int Mystrcmp(char s1[], char s2[]) {
    
    int i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    
    return (s1[i] - s2[i]); //ATENCAOOOOOOOO!!!!
}

char *Mystrstr (char s1[], char s2[]) {
    int i = 0, j = 0, w = 0;
    
    while (s1[i] != '\0') {
        
        if (s1[i] == s2[0]) {
            j = 0;
            w = i; // guardar a posição do i
            while (s1[i] == s2[j] && s2[j] != '\0') {
                i++;
                j++;
            }
            i = w; // restaurar a posição do i
            i++;
        }
        
        else i++;
    }

    if (s2[j] == '\0') return (s1+w);
    else return NULL;
}

void Mystrrev (char s[]) {

    int i;
    
    for (i = 0; s[i] != '\0'; i++);
    
    int size = i-1;
    char tmp[size];
    
    for (i = 0; s[i] != '\0'; i++) {
        tmp[i] = s[i];
    }
    
    int j = 0;
    for (i = size; i >= 0; i--) {
        s[j] = tmp[i];
        j++;
    }
}

void strnoV (char t[]){
    
    int j = 0;
    int i = 0;
    
    while (t[i] != '\0') {
        
        if (t[i] != 'A' && t[i] != 'E' && t[i] != 'I' && t[i] != 'O' && t[i] != 'U' && t[i] != 'a' &&
        t[i] != 'e' && t[i] != 'i' && t[i] != 'o' && t[i] != 'u') {
            
            t[j] = t[i];
            j++;
            
        }
        i++;
    }
    t[j]='\0';
}

void truncW (char t[], int n) {
    int i;
    int j = 0; 
    int w = n;
    
    for (i = 0; t[i]; i++) {
        
        if (t[i] == ' ') {
            n = w;
            t[j] = t[i];
            j++;   
        }
        else if (n != 0) {
            t[j] = t[i];
            n--;
            j++;
        }
    }
    t[j] = '\0';
}

char charMaisfreq (char s[]) {
    int i, j;
    char m = s[0];
    int mquantos = 0;
    int contador;
    
    for(i = 0; s[i]; i++) {
        contador = 0;
        for (j = 0; s[j]; j++) {
            if (s[j] == s[i]) contador++;
        }
        
        if (contador > mquantos) {
            mquantos = contador;
            m = s[i];
        }
    }
    
    return m;
}

int iguaisConsecutivos (char s[]) {
    int i = 0;
    int maior = 0;
    int contador;
    int w;
    
    while (s[i]) {
        
        contador = 1;
        w = i;
        while (s[i] == s[i+1]) {
            contador++;
            i++;
        }
        
        if (contador > maior) {
            maior = contador;
        }
        
        i = w;
        i++;
       
    }
    
    return maior;
}

int difConsecutivos (char s[]) {
    int i;
    int maior = 0;
    int j=0;
    int contador = 0;
    int g=0;
    
    for (i = 0; s[i]; i++) {
        j = i-1;
        contador = 1;
        while (j > g && s[j] != s[i]) {
            contador++;
            j--;   
        }
        if (contador > maior) maior = contador;
        g = j;
        }
        
    return maior;
}

int maiorPrefixo (char s1 [], char s2 []) {
    int i = 0;
    int j = 0;
    int comprimento = 0;
    
    while (s1[i] == s2[j]) {
        comprimento++;
        i++;
        j++;
    }
    
    return comprimento;
}

int maiorSufixo (char s1 [], char s2 []) {
    int i;
    int j;
    int comprimento = 0;
    
    for (i = 0; s1[i]; i++);
    for (j = 0; s2[j]; j++);
    
    i--;
    j--;
    
    while (s1[i] == s2[j]) {
        comprimento++;
        i--;
        j--;
    }
    
    return comprimento;
}

int sufPref (char s1[], char s2[]) {
    
    int i = 0;
    int j;
    int maior = 0;
    
    while (s1[i]) {
        
        j = 0;
        while (s1[i] == s2[j] && s1[i] && s2[j]) {
            j++;
            i++;
        }
        
        if (s1[i] != '\0') j = 0;
        
        if (j > maior) maior = j;
        i++;
    }
    
    return maior;
}

int sufPref1 (char s1[], char s2[]) {
    
    int i = strlen(s1) - 1;
    int j = 0;
    int notFound = 0;
    
    while (s1[i] && s2[j]) {
        
        printf("\n%c %c\n", s1[i], s2[j]);
        printf("%d %d ------------\n", i, j);
        
        int k = strlen(s1) - 1, l = j, notFound = 0;
        for (; k >= i && l >= 0; k--, l--) {
            
            printf("%c %c\n", s1[k], s2[l]);
            
            if (s1[k] != s2[l]) {
                
                notFound = 1;
                printf("Not equal\n\n");
                break;
            }
        }
        
        if (notFound == 0) {
            return j + 1;
        }
            
        i--;
        j++;
    }
    
    return 0;
}


int contaPal (char s[]) {
    
    int i = 0;
    int palavras = 0;
    
    while (s[i]) {
        if(s[i] != ' ' && (s[i+1] == ' ' || s[i+1] == '\0')) {
            palavras++;
        }
        i++;
    }
    
    return palavras;
}

int contaVogais (char t[]) {
    int i = 0,j = 0;
    while (t[i] != '\0') { 
        if ((t[i] == 'a') || (t[i] == 'e') || (t[i] == 'i') || (t[i] == 'o') || (t[i] == 'u') || (t[i] == 'A') 
        || (t[i] == 'E') || (t[i] == 'I') || (t[i] == 'O') || (t[i] == 'U')) j++;;
        i++;
    }
    return j;
}

int contida (char a[], char b[]) {
    
    int i = 0;
    int found = 0;
    int j;
   
    while (a[i]) {
        
        j = 0;
        found = 0;
        while (b[j]) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
            j++;
        }
        
        if (found == 0) return 0;
        i++;
        
    }
    
    return 1;
    
}

int palindroma (char s[]) {
    
    int i = 0;
    int j = strlen(s) - 1;
    
    while (s[i]) {
        
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        
        else return 0;
    }
    
    return 1;
}

int remRep (char texto[]) {

    int i = 0;
    int j = 0;
        
    while (texto[i]) {
        
        if (texto[i] != texto[i+1]) {
            texto[j] = texto[i];
            j++;
        }
        
        i++;
        
    }
    
    texto[j] = '\0';
    
    return j;

}

int limpaEspacos (char texto[]) {
    int i = 0;
    int j = 0;
    
    while (texto[i]) {
        
        if (texto[i] != ' ' || texto[i+1] != ' ') {
            texto[j] = texto[i];
            j++;
        }
        
        i++;
    
    }
    
    texto[j] = '\0';    
    
    return j;
}

void insere (int v[], int N, int x) {
    
    while (N > 0 && v[N-1] > x) {
        v[N] = v[N-1];
        N--;
    }
    
    v[N] = x;
}

void merge (int r [], int a[], int b[], int na, int nb) {
       
   int i = 0;
   int j = 0;
   int l = 0;
   
   while (i < na && j < nb) {
       
       if (a[i] <= b[j]) {
           
           r[l] = a[i];
           i++;
           l++;
       }
       else {
           
           r[l] = b[j];
           j++;
           l++;
        }
   }
    // se o array A já chegou ao fim    
    if (i == na) {
        while (j < nb) {
            r[l] = b[j]; l++; j++;
        }
    }
    
    // se o array B já chegou ao fim 
    if (j == nb) {
        while (i < na) {
            r[l] = a[i]; l++; i++;
        }
    }
}

int crescente (int a[], int i, int j) {
    
    while (i < j) {
        if (a[i] > a[i+1]) return 0;
        i++;
    }
       
       return 1;
}

int retiraNeg (int v[], int N){
    int i = 0;
    int j = 0;
    
    while (N > 0) {
        if (v[i] > 0) {
            v[j] = v[i];
            j++;
        }
        N--;
        i++;
    }
    
    return j;
}

int menosFreq (int v[], int N){
    
    int guardado = INT_MAX;
    int indice;
    int i = 0;
    int valor = 0;
    
    int contador;
    
    while (N > 0) {
        
        contador = 0;
        while (v[i] == v[i+1]) {
            contador++;
            i++;
            N--;
        }
        
        if (contador < guardado) {
            guardado = contador;
            indice = i;
            valor = v[i];
        }
        else if (contador == guardado) {
            if (i < indice) {
                guardado = contador;
                indice = i;
                valor = v[i];
            }
        }
        
        i++;
        N--;
        
    }
           
    return valor;       
}

int maisFreq (int v[], int N){
    
    int guardado = 0;
    int indice;
    int i = 0;
    int valor = 0;
    
    int contador;
    
    while (N > 0) {
        
        contador = 0;
        while (v[i] == v[i+1]) {
            contador++;
            i++;
            N--;
        }
        
        if (contador > guardado) {
            guardado = contador;
            indice = i;
            valor = v[i];
        }
        else if (contador == guardado) {
            if (i < indice) {
                guardado = contador;
                indice = i;
                valor = v[i];
            }
        }
        
        i++;
        N--;
        
    }
           
    return valor;       
}

int maxCresc (int v[], int N) {
    
    int comp;
    int maior = 0;
    int i = 0;

       while (N > 0) {
            comp = 1;           
            while (v[i+1] >= v[i]) {
                comp++;
                i++;
                N--;
            }
            
            if (comp > maior) maior = comp;
            
            i++;
            N--;
       }
       
       return maior;
}









int main () {

    // Testar BitsUM
    printf("BitsUM: %d\n", bitsUm(20));

    // Testar TrailingZ
    printf("TrailingZ: %d\n", trailingZ(20));

    // Testar qDig
    printf("qDig: %d\n", qDig(2000));

    // Testar strCat
    char s1[] = "Sérgio";
    char s2[] = "Jorge";
    char *p;
    p = Mystrcat(s1, s2);
    p = Mystrcpy(s1, s2);
    p = Mystrstr(s1, s2);


    return 0;
}
