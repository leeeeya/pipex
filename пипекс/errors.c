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
		write(2, "ERROR: Memory allocation error", 30);
		exit(12);
	}
}

void	other_error_handler(int err)
{
	if (err == 1)
	{
		write(2, "ERROR: Wrong number of arguments", 32);
		exit(1);
	}
	if (err == 2)
	{
		write(2, "ERROR: No such file or directory", 32);
		exit(2);
	}
	if (err == 22)
	{
		write(2, "ERROR: Invalid arguments", 24);
		exit(22);
	}
}

void error_handler(int value, const char *error)
{
	if (value < 0)
	{
		perror(error);
		exit(errno);
	}
}
