/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:08:25 by cstefany          #+#    #+#             */
/*   Updated: 2022/01/10 18:08:29 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void close_pfd(int *fd1, int *fd2, int **pipefd)
{
	int i = 0;
	while(pipefd[i] != NULL)
	{
		if (&pipefd[i][0] != fd1 || &pipefd[i][0] != fd2 || &pipefd[i][1] != fd1 || &pipefd[i][1] != fd2)
			close(pipefd[i][0]);
		if (&pipefd[i][0] != fd1 || &pipefd[i][0] != fd2 || &pipefd[i][1] != fd1 || &pipefd[i][1] != fd2)
			close(pipefd[i][1]);
		i++;
	}
}

int	open_output(char *argv)
{
	int	fd_output;

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
	return (fd_output);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	*child;
	t_list	*cmd_list;
	int		io_fd[2];
	int		**pipe_fd;
	int		*status;
	int		i;
	int		cmd_no;

	cmd_no = argc -3;
	i = 0;

	printf("%s\n", "parent");

	child = (pid_t *)malloc(sizeof(pid_t) * cmd_no);
	status = (int *)malloc(sizeof(int) * cmd_no);
	pipe_fd = (int **)malloc(sizeof(int *) * (cmd_no - 1));
	while(i != cmd_no - 1)
	{

		pipe_fd[i] = (int *)malloc(sizeof (int));
		i++;
	}
	i = 0;
	io_fd[0] = open(argv[1], O_RDONLY, 0777);
	error_handler(io_fd[0], "Open");
	io_fd[1] = open_output(argv[argc - 1]);
	cmd_list = check_arguments(argc, argv, envp);

//	while(i != cmd_no)
//	{
//		if (i == 0)
//		{
//			printf("child %d\n", i + 1);
//			error_handler(pipe(pipe_fd[i]), "Pipe");
//			child[i] = fork();
//			error_handler(child[i], "Fork");
//			if (child[i] == 0)
//			{
//				close_pfd(&io_fd[0], &pipe_fd[i][1], (int **)pipe_fd);
//				error_handler(dup2(io_fd[0], STDIN_FILENO), "Dup 86");
//				error_handler(dup2(pipe_fd[i][1], STDOUT_FILENO), "Dup 87");
//				execve(cmd_list->cmd[0], cmd_list->cmd, envp);
//			}
//		}
//		cmd_list = cmd_list->next;
//		i++;
//		if (i == cmd_no - 1)
//		{
//			child[i] = fork();
//			error_handler(child[i], "Fork");
//			if (child[i] == 0)
//			{
//				printf("child %d\n", i + 1);
//				close_pfd(&pipe_fd[i - 1][0], &io_fd[1], (int**)pipe_fd);
//				error_handler(dup2(pipe_fd[i - 1][0], STDIN_FILENO), "Dup 100");
//				error_handler(dup2(io_fd[1], STDOUT_FILENO), "Dup 101");
//				execve(cmd_list->cmd[0], cmd_list->cmd, envp);
//			}
//		}
//		else if (i < cmd_no - 1)
//		{
//			printf("child %d\n", i + 1);
//			error_handler(pipe(pipe_fd[i]), "Pipe");
//			child[i] = fork();
//			error_handler(child[i], "Fork");
//			if (child[i] == 0) {
//				close_pfd(&pipe_fd[i][1], &pipe_fd[i - 1][0], (int **) pipe_fd);
//				error_handler(dup2(pipe_fd[i - 1][0], STDIN_FILENO), "Dup 111");
//				error_handler(dup2(pipe_fd[i][1], STDOUT_FILENO), "Dup 112");
//				execve(cmd_list->cmd[0], cmd_list->cmd, envp);
//			}
//		}
//	}

	// todo посомтреть где какие дочки создаются
	i = 0;
	while(i != cmd_no - 1)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
	i = 0;
	while(i != cmd_no)
	{
		printf("%d\n", child[i]);
		i++;
	}
	i = 0;
	printf("%s\n", "where is the child?");
	while(i != cmd_no)
	{
		error_handler(waitpid(child[i], &status[i], 0), "waitpid");
		i++;
	}

	close_fd(io_fd[0], io_fd[1]);
	return (0);
}
