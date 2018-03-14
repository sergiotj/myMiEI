#include <stdio.h>
#include <string.h>
#include <time.h>

/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

int main() {

    clock_t tStart, tEnd;
	double elapsed;
	tStart = clock();


    int n1 = 0;
    int n2;
    int result;
    int max = 0;
    int maxN1 = 0;
    int maxN2 = 0;
    int flag = 0;

    while (n1 <= 999) {

        n2 = 0;

        while (n2 <= 999) {

            flag = 0;
            result = n1 * n2;
            char str[12];
            sprintf(str, "%d", result);

            int i = 0;
            int j = strlen(str)-1;

            while (j > 2 && str[i] == str[j]) {

                i++;
                j--;

            }

            i--, j++;

            if (i == 2 && j == 3) flag = 1;

            if (result > max && flag == 1) {

                max = result;
                maxN1 = n1;
                maxN2 = n2;
            }

            n2++;

        }

    n1++;

    }

    printf("Multiplicando %d por %d que dá o resultado %d. É o maior resultado palíndrome com 6 algarismos.\n", maxN1, maxN2, max);
    tEnd = clock();
    elapsed = (tEnd - tStart) * 1000.0 / CLOCKS_PER_SEC;
    printf("O programa demorou %g ms. \n", elapsed);

    return 0;

}
