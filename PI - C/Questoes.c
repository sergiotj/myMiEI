
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int mystrcmp(char s1[], char s2[]) {
    
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
