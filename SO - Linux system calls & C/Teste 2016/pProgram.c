#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){

    char okArray[] = "OK\n";

    time_t start, end;
    double elapsed;
    start = time(NULL);
    int terminate = 1;
    while (terminate) {

        write(1, okArray, strlen(okArray));

        end = time(NULL);
        elapsed = difftime(end, start);
        if (elapsed >= 12.0)
            terminate = 0;

        else sleep(3);
    }

    return 0;
}

