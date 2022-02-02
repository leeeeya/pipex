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

#include "pipex_bonus.h"

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

void	child_exe(t_list *cmds, char **env)
{
	pid_t	child;
	int		pipe_fd[2];
	int		status;

	pipe(pipe_fd);
	child = fork();
	error_handler(child, "Fork");
	if (child != 0)
	{
		error_handler(close (pipe_fd[1]), "Close");
		error_handler(dup2(pipe_fd[0], STDIN_FILENO), "Dup");
		error_handler(waitpid(child, &status, 0), "Waitpid");
	}
	else
	{
		close(pipe_fd[0]);
		error_handler(dup2(pipe_fd[1], STDOUT_FILENO), "Dup 57");
		error_handler(execve(cmds->cmd[0], cmds->cmd, env), "execve");
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*cmd_list;
	int		io_fd[2];
	int		cmd_no;
	int		i;

	cmd_no = argc - 3;
	i = 0;
	io_fd[0] = open(argv[1], O_RDONLY);
	error_handler(io_fd[0], "Open");
	io_fd[1] = open_output(argv[argc - 1]);
	cmd_list = check_arguments(argc, argv, envp);
	error_handler(dup2(io_fd[0], STDIN_FILENO), "Dup");
	error_handler(dup2(io_fd[1], STDOUT_FILENO), "Dup");
	while (i < cmd_no - 1)
	{
		child_exe(cmd_list, envp);
		cmd_list = cmd_list->next;
		i++;
	}
	error_handler(execve(cmd_list->cmd[0], cmd_list->cmd, envp), "execve");
	error_handler(close(io_fd[0]), "Close");
	error_handler(close(io_fd[1]), "Close");
	return (0);
}
