
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


ssize_t readln(int fildes, void *buffer, size_t nbyte) {

    char* buf = buffer;
    char c;
    ssize_t j;
    int bytesRead = 0;

    do {

        j = read(fildes, &c, 1);

        if (j > 0) {
            buf[bytesRead] = c;
            bytesRead++;

        } else if (j < 0) {
			buf[bytesRead] = '\0';
			return j;

		} else {
			return j;
		}

    } while (bytesRead < nbyte && c != '\n' && j > 0);

    buf[bytesRead] = '\0';

    // Devolve o numero de bytes lidos
	return bytesRead;

}


int main(int argc, char* argv []) {

    int fd;
    int fdRead;

    remove("testeEX5.txt");
    fd = open("testeEX5.txt", O_WRONLY | O_APPEND | O_CREAT);

    char linha1[] = "Portugal é um país ocidental.\n";
    char linha2[] = "Universidade do Minho.\n";

    // escrever linhas de teste
    write(fd, linha1, strlen(linha1));
    write(fd, linha2, strlen(linha2));
    close(fd);

    fdRead = open("testeEX5eEX6.txt", O_RDONLY | O_APPEND);

    // máximo de 1000 bytes por linha
    char buffer[1000];

    // o 1000 passado aqui é o máximo de bytes por linha
    int i = 1;
    char linha[1000];

    while (readln(fdRead, buffer, 1000) > 0) {
        sprintf(linha, "Estamos na linha %d -> ", i);
        strcat(linha, buffer);
        write(1, linha, strlen(linha));
        i++;
    }

    close(fdRead);

    return 0;

}
