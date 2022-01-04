//
// Created by Claribel Stefany on 12/14/21.
//

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "lib/libft.h"

int check_arguments(int argc, char *argv[], char *envp[]);
int main(int argc, char *argv[], char *envp[]);
int errors();

#endif //PIPEX_H
