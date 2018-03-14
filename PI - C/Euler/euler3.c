#include <stdio.h>
#include <math.h>

/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

void primeFactors(long int n) {

    printf("Os factores primos são ");

    while (n%2 == 0) {
        printf("%d, ", 2);
        n = n/2;
    }


   for (int i = 3; i <= sqrt(n); i = i+2) {

        while (n%i == 0) {

            printf("%d, ", i);
            n = n/i;
        }
    }

    if (n > 2) printf ("%d.", n);

    return;

}



int main() {

    primeFactors(600851475143);

    return 0;

}
