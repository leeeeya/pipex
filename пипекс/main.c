#include <stdio.h>
#include <unistd.h>
//#include <sys/types.h>
#include "pipex.h"

int main(int ac, char **av, char **envp) {
    char *arg[] = {"/bin/ls", "-la", NULL};
	pid_t pid;

	pid = fork();
	// todo проверка на -1 незабудь :*
	printf("TEST!\n");
	if (pid == 0) {
		sleep(1);
		printf("Kill child\n");
		execve("/bin/ls", arg, envp);
		exit(1);
	}
	else {
		printf("HELLO WORLD!\n");
		wait(0);
	}
}