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

    char okArray[] = "Programa OK\n";

    while (1) {

        write(1, okArray, strlen(okArray));
    }

    return 0;
}

