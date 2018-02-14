#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <string.h>


ssize_t readLine(int fd, char* buffer, long maxBytes) {

    long bytesRead = 0;
    ssize_t i;
    char c;

    int lines = 0;

    do {

        i = read(fd, &c, 1);

        if (i > 0) {
            buffer[bytesRead] = c;
            bytesRead++;

        }

    } while (i > 0 && bytesRead < maxBytes && c != 'a');

    buffer[bytesRead] = '\0';

    // Devolver o numero de bytes lidos
    return bytesRead;
}


int main(int argc, char *argv[]){

    char array[] = "YOUR TEXT HERE";

    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT);

    write(fd, array, strlen(array));
    close(fd);

    fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT);
    char buffer[500];
    int bytesRead = 1;

    while (bytesRead > 0) {

        bytesRead = readLine(fd, buffer, 1000);
    }

    write(1, buffer, bytesRead);

    return bytesRead;
}

