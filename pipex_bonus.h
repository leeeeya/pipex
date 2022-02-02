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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "lib/libft.h"

t_list	*check_arguments(int argc, char *argv[], char *envp[]);
int		main(int argc, char *argv[], char *envp[]);
void	mem_error_handler(void *mem, int str);
void	other_error_handler(int err);
void	error_handler(int value, const char *error);
void	access_files(int argc, char **argv);

#endif
