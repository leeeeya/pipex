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

#include "pipex_bonus.h"

void	mem_error_handler(void *mem, int str)
{
	if (!mem)
	{
		write(2, "ERROR: Memory allocation error\n", 31);
		printf("(%d)\n", str);
		exit(12);
	}
}

void	other_error_handler(int err)
{
	if (err == 1)
	{
		write(2, "ERROR: Wrong number of arguments", 33);
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

void	access_files(int argc, char **argv)
{
	if (argc < 5)
		other_error_handler(1);
	if (access(argv[1], R_OK) != 0)
		other_error_handler(2);
	if (access(argv[argc], W_OK) != 0 && !access(argv[argc], F_OK))
		other_error_handler(2);
}
