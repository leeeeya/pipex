/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:31:34 by cstefany          #+#    #+#             */
/*   Updated: 2022/01/05 19:31:38 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**join_slash(char **path)
{
	int		i;
	char	**res_paths;

	i = 0;
	while (path[i] != NULL)
		i++;
	res_paths = (char **)ft_calloc(i + 1, sizeof(char *));
	mem_error_handler(res_paths);
	i = 0;
	while (path[i] != NULL)
	{
		res_paths[i] = ft_strjoin(path[i], "/");
		mem_error_handler(res_paths[i]);
		i++;
	}
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	return (res_paths);
}

const char	**search_path(char *envp[])
{
	int			i;
	const char	**path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", ft_strlen("PATH=")))
		i++;
	envp[i] = ft_strtrim(envp[i], "PATH=");
	mem_error_handler(envp[i]);
	path = (const char **)ft_split(envp[i], ':');
	mem_error_handler(path);
	path = (const char **) join_slash((char **)path);
	mem_error_handler(path);
	return (path);
}

char	*validation_check(char *arg, const char **path)
{
	char	*tmp_arg;
	int		i;

	i = -1;
	if (access(arg, F_OK) == 0)
		return (arg);
	else
	{
		tmp_arg = ft_strdup(arg);
		mem_error_handler(tmp_arg);
		free(arg);
		while (path[++i])
		{
			arg = ft_strjoin(path[i], tmp_arg);
			mem_error_handler(arg);
			if (access(arg, F_OK) == 0)
			{
				free(tmp_arg);
				return (arg);
			}
			else
				free(arg);
		}
	}
	return (NULL);
}

char	**check_command(const char *argv, const char **path)
{
	char	**true_path;

	true_path = NULL;
	true_path = ft_split(argv, ' ');
	mem_error_handler(true_path);
	true_path[0] = validation_check(true_path[0], path);
	if (!true_path[0])
	{
		other_error_handler(22);
		return (NULL);
	}
	else
		return (true_path);
}

list	check_arguments(int argc, char *argv[], char *envp[])
{
	const char	**paths_list;
	list		cmd_list;
	int			i;

	i = 0;
	cmd_list.cmd1 = NULL;
	cmd_list.cmd2 = NULL;
	if (argc != 5)
		other_error_handler(1);
	if (access(argv[1], R_OK) != 0)
		other_error_handler(2);
	if (access(argv[4], W_OK) != 0 && !access(argv[4], F_OK))
		other_error_handler(2);
	paths_list = search_path(envp);
	cmd_list.cmd1 = check_command(argv[2], paths_list);
	cmd_list.cmd2 = check_command(argv[3], paths_list);
	while (paths_list[i] != NULL)
	{
		free((void *)paths_list[i]);
		i++;
	}
	free(paths_list);
	return (cmd_list);
}
