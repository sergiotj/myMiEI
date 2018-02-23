
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>
#include <stdio.h>
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */


/*
** int open(const char *path, int oflag [, mode]);
** ssize_t read(int fildes, void *buf, size_t nbyte);
** ssize_t write(int fildes, const void *buf, size_t nbyte);
** int close(int fildes);
**pid_t getpid(void);
**pid_t getppid(void);
**pid_t fork(void);
**void _exit(int status);
**pid_t wait(int *status);
**pid_t waitpid(pid_t pid, int *status, int options);
**int WIFEXITED(int status);
**int WEXITSTATUS(int status);
*/

int main(int argc, char* argv []) {

    pid_t child = fork();

    if (child == 0) {

        printf("Filho: Olá!! Eu sou o filho processo...\n");
        printf("Filho: O meu pid é %d\n", getpid());
        printf("Filho: O pid do meu pai é %d\n", getppid());

    }

    else {

        // espera pelo fim do filho
        wait(&child);

        printf("Pai: Olá!! Eu sou o pai processo...\n");
        printf("Pai: O meu pid é %d\n", getpid());
        printf("Pai: O pid do meu pai é %d\n", getppid());
    }

    return 0;

}
