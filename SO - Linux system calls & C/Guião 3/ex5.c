#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

/*
int execl(const char *path, const char *arg0, ..., NULL);
int execlp(const char *file, const char *arg0, ..., NULL);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
*/

// executar ls -l
int main(int argc, char *argv[]) {

    pid_t childID;
    int status;
    int exitstatus;

    for(int i = 1; i < argc; i++) {

        childID = fork();

        if (childID == 0) {

            execlp(argv[i],argv[i], NULL);
            exit(0);

        }
    }

    // espera pelo fim dos filhos
    while (wait(&status) > 0) {
        exitstatus = WEXITSTATUS(status);
        printf("Pai: O processo terminou com o código de saída %d.\n", exitstatus);
    }

    printf("Pai: Todos os processos terminaram.");

}
