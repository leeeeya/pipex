/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:11:05 by cstefany          #+#    #+#             */
/*   Updated: 2022/01/10 18:11:07 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "lib/libft.h"

typedef struct list_of_args
{
	char	**cmd1;
	char	**cmd2;
	char	**envp;
}	t_cmd;
typedef struct set_fd
{
	int	pipe_fd[2];
	int	fd_input;
	int	fd_output;
}	t_fd;

t_cmd	check_arguments(int argc, char *argv[], char *envp[]);
int		main(int argc, char *argv[], char *envp[]);
void	mem_error_handler(void *mem);
void	other_error_handler(int err);
void	error_handler(int value, const char *error);
void	close_fd(int fd1, int fd2);

#endif
