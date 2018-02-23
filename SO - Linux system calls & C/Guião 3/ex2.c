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
int main(int argc, char const *argv[]) {

    pid_t childID;

    childID = fork();

    if (childID == 0) {

        execlp("ls", "ls", "-l", NULL);
        exit(-1);

    }

    else {

        wait(0);

    }

}
