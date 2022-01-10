//
// Created by Claribel Stefany on 12/17/21.
//

# include "pipex.h"

void dup_fd(int child, int pipe_fd[], int fd_io)
{
	int close_fd;
	int first_dup;
	int sec_dup;

	if (child == 1)
	{
		close_fd = pipe_fd[0];
		first_dup = fd_io;
		sec_dup = pipe_fd[1];
	}
	else
	{
		close_fd = pipe_fd[1];
		first_dup = pipe_fd[0];
		sec_dup = fd_io;
	}
	close(close_fd);
	error_handler(dup2(first_dup, STDIN_FILENO), "Dup");
	error_handler(dup2(sec_dup, STDOUT_FILENO), "Dup");
}

//void child_exe(pid_t child, int *pipe_fd, int fd_io, list cmd_list)
//{
//	error_handler(child, "Fork");
//	if (child == 0)
//	{
//		dup_fd(chld_no, pipe_fd, fd_io);
//		if (chld_no == 1)
//			execve(cmd_list.cmd1[0], cmd_list.cmd1++, cmd_list.envp);
//		else
//			execve(cmd_list.cmd2[0], cmd_list.cmd2++, cmd_list.envp);
//	}
//}



int open_output(char *argv)
{
	int fd_output;

	if (access(argv, F_OK) != 0)
	{
		fd_output = open(argv, O_CREAT | O_RDWR, 0777);
		error_handler(fd_output, "Open");
	}
	else
	{
		fd_output = open(argv, O_RDWR);
		error_handler(fd_output, "Open");
	}
	return(fd_output);
}


int main(int argc, char *argv[], char *envp[])
{
	int pipe_fd[2];
	pid_t child1;
	pid_t child2;
	list cmd_list;
	int fd_input;
	int fd_output;
	int status;

	fd_input = open(argv[1], O_RDONLY, 0777);
	error_handler(fd_input,"Open");
	fd_output = open_output(argv[4]);
	cmd_list = check_arguments(argc, argv, envp);
	cmd_list.envp = envp;
	error_handler(pipe(pipe_fd), "Pipe");
	child1 = fork();
	error_handler(child1, "Fork");
//	child_exe(1, pipe_fd, fd_input, cmd_list);
	if (child1 == 0)
	{
		dup_fd(1, pipe_fd, fd_input);
		execve(cmd_list.cmd1[0], cmd_list.cmd1++, cmd_list.envp);
	}
	child2 = fork();
//	child_exe(2, pipe_fd, fd_output, cmd_list);
	error_handler(child2, "Fork");
	if (child2 == 0)
	{
		dup_fd(2, pipe_fd, fd_output);
		execve(cmd_list.cmd2[0], cmd_list.cmd2++, cmd_list.envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	close(fd_input);
	close(fd_output);
	return 0;
}
