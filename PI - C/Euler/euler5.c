#include <stdio.h>
#include <string.h>
#include <time.h>

/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

int main() {

    clock_t tStart, tEnd;
	double elapsed;
	tStart = clock();

    int divider = 1;
    int testNumber = 1;

    while (divider <= 20) {

        if (testNumber%divider == 0) {
            divider++;
        }

        else {
            divider = 1;
            testNumber++;
        }
    }

    printf("Retornou o número %d.\n", testNumber);

    tEnd = clock();
    elapsed = (tEnd - tStart) * 1000.0 / CLOCKS_PER_SEC;
    printf("O programa demorou %g ms. \n", elapsed);

    return 0;

}
