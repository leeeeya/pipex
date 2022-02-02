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

void	child_exe(int child, t_fd fd, t_cmd cmd)
{
	int	close_fd;
	int	first_dup;
	int	sec_dup;

	if (child == 1)
	{
		close_fd = fd.pipe_fd[0];
		first_dup = fd.fd_input;
		sec_dup = fd.pipe_fd[1];
	}
	else
	{
		close_fd = fd.pipe_fd[1];
		first_dup = fd.pipe_fd[0];
		sec_dup = fd.fd_output;
	}
	error_handler(close(close_fd), "Close");
	error_handler(dup2(first_dup, STDIN_FILENO), "Dup");
	error_handler(dup2(sec_dup, STDOUT_FILENO), "Dup");
	if (child == 1)
		error_handler(execve(cmd.cmd1[0], cmd.cmd1, cmd.envp), "execve");
	else
		error_handler(execve(cmd.cmd2[0], cmd.cmd2, cmd.envp), "execve");
}

int	open_output(char *argv)
{
	int	fd_output;

	if (access(argv, F_OK) != 0)
	{
		fd_output = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
		error_handler(fd_output, "Open");
	}
	else
	{
		fd_output = open(argv, O_RDWR | O_TRUNC);
		error_handler(fd_output, "Open");
	}
	return (fd_output);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	child[2];
	t_cmd	cmd_list;
	t_fd	fd;
	int		status[2];

	cmd_list = check_arguments(argc, argv, envp);
	fd.fd_input = open(argv[1], O_RDONLY);
	error_handler(fd.fd_input, "Open");
	fd.fd_output = open_output(argv[4]);
	cmd_list.envp = envp;
	error_handler(pipe(fd.pipe_fd), "Pipe");
	child[0] = fork();
	error_handler(child[0], "Fork");
	if (child[0] == 0)
		child_exe(1, fd, cmd_list);
	child[1] = fork();
	error_handler(child[1], "Fork");
	if (child[1] == 0)
		child_exe(2, fd, cmd_list);
	close_fd(fd.pipe_fd[0], fd.pipe_fd[1]);
	error_handler(waitpid(child[0], &(status[0]), 0), "waitpid");
	error_handler(waitpid(child[1], &(status[2]), 0), "waitpid");
	close_fd(fd.fd_input, fd.fd_output);
	return (0);
}
