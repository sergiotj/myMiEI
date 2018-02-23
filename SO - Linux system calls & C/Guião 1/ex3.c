
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>
#include <stdlib.h>


/*
** int open(const char *path, int oflag [, mode]);
** ssize_t read(int fildes, void *buf, size_t nbyte);
** ssize_t write(int fildes, const void *buf, size_t nbyte);
** int close(int fildes);
*/


int main(int argc, char* argv []) {

    char buffer[10000];
    int bytesALer = atoi(argv[1]);

    while (read(0, buffer, bytesALer) > 0) {

        write(1, buffer, strlen(buffer));

    }

    return 0;

}
