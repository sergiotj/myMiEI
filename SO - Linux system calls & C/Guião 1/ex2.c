
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>
#include <stdio.h>


/*
** int open(const char *path, int oflag [, mode]);
** ssize_t read(int fildes, void *buf, size_t nbyte);
** ssize_t write(int fildes, const void *buf, size_t nbyte);
** int close(int fildes);
*/


int main(int argc, char* argv []) {

    int fd;
    remove (argv[1]);
    fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND);
    int writtenBytes = 0;

    while (writtenBytes < 1000000) {
        write(fd, "abcdefghij", 10);
        writtenBytes++;
    }

    return 0;

}
