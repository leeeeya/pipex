#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

// STRERROR, PERROR

void handlerError(int err) {
    if (err < 0) {
//        write(2, msg, strlen(msg));
        perror(strerror(errno));
    }
}

int errors() {
     int res;

     res = open("./print.c", O_RDONLY);
     handlerError(res);

   	exit(errno);

}