
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


// criação de 10 processos concorrentes
int main(int argc, char* argv []) {

    int status;
    int exitstatus;

    for (int i = 0; i < 10; i++) {

        pid_t child = fork();

        if (child == 0) {

            // vamos atrasar o processo 5, 2 segundos, para vermos se é o último a sair e se o pai espera
            if (i == 5) sleep(2);

            _exit(i);

        }
    }

        // espera pelo fim dos filhos
        while (wait(&status) > 0) {
            exitstatus = WEXITSTATUS(status);
            printf("Pai: O processo terminou com o código de saída %d.\n", exitstatus);
        }

        printf("Pai: Todos os processos terminaram.");

    return 0;

}
