#include <stdio.h>
#include <string.h>
#include <time.h>

/*

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int main() {

    clock_t tStart, tEnd;
	double elapsed;
	tStart = clock();

    int i = 1;
    int sum = 0;
    int sumSquares = 0;

    while (i <= 100) {

        sumSquares += i * i;
        sum += i;
        i++;
    }

    int squareSum = sum * sum;

    int result = squareSum - sumSquares;

    printf("Retornou o número %d.\n", result);

    tEnd = clock();
    elapsed = (tEnd - tStart) * 1000.0 / CLOCKS_PER_SEC;
    printf("O programa demorou %g ms. \n", elapsed);

    return 0;

}
