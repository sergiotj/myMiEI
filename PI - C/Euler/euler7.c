#include <stdio.h>
#include <string.h>
#include <time.h>

/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

int main() {

    clock_t tStart, tEnd;
	double elapsed;
	tStart = clock();



    printf("Retornou o número %d.\n", result);

    tEnd = clock();
    elapsed = (tEnd - tStart) * 1000.0 / CLOCKS_PER_SEC;
    printf("O programa demorou %g ms. \n", elapsed);

    return 0;

}
