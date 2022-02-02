/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:32:00 by cstefany          #+#    #+#             */
/*   Updated: 2022/01/05 19:32:04 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mem_error_handler(void *mem)
{
	if (!mem)
	{
		write(2, "ERROR: Memory allocation error\n", 31);
		exit(12);
	}
}

void	other_error_handler(int err)
{
	if (err == 1)
	{
		write(2, "ERROR: Wrong number of arguments\n", 33);
		exit(1);
	}
	if (err == 2)
	{
		write(2, "ERROR: No such file or directory\n", 33);
		exit(2);
	}
	if (err == 22)
	{
		write(2, "ERROR: Invalid arguments\n", 25);
		exit(22);
	}
	if (err == 8)
	{
		write(2, "invalid command declaration\n", 28);
		exit(8);
	}
}

void	error_handler(int value, const char *error)
{
	if (value < 0)
	{
		perror(error);
		exit(errno);
	}
}

void	close_fd(int fd1, int fd2)
{
	error_handler(close(fd1), "Close");
	error_handler(close(fd2), "Close");
}
