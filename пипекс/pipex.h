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

typedef struct some_struct
{
	char **cmd1;
	char **cmd2;
	char **envp;
} list;
list check_arguments(int argc, char *argv[], char *envp[]);
int main(int argc, char *argv[], char *envp[]);
void mem_error_handler(void *mem);
void other_error_handler(int err);
void error_handler(int value, const char *error);

#endif //PIPEX_H
