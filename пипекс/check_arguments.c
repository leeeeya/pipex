
// errno??????


#include "pipex.h"
#include "lib/libft.h"


char **search_path(char *envp[])
{
	int i = 0;
	char **path;

	while (!ft_strnstr(envp[i], "PATH=", ft_strlen("PATH=")))
		i++;
	envp[i] = ft_strtrim(envp[i], "PATH=");
	if (envp[i] == NULL)
		return NULL;
	path = ft_split(envp[i], ':');
	if (path == NULL)
		return NULL;
	return (path);
}


char *validation_check(char *arg_stack, char **dup_path)
{
	char *tmp;
	char *tmp_arg;
	int i = 0;

	char *arg = ft_strdup(arg_stack);
	char **path;

	if (access(arg, F_OK) == 0)
		return (arg);
	else
	{
		while(dup_path[i] != NULL)
			i++;
		path = (char **)ft_calloc(i, sizeof (char *));
		i = 0;
		while(dup_path[i] != NULL)
		{
			path[i] = ft_strdup(dup_path[i]);
			i++;
		}
		i = 0;
		while (path[i])
		{
			tmp_arg = ft_strdup(arg);
			tmp = ft_strjoin("/", arg);
			free(arg);
			arg = ft_strjoin(path[i], tmp);
			free(path[i]);
			free(tmp);
			if (arg == NULL)
				return NULL;
			if (access(arg, F_OK) == 0)
			{
				i++;
				while(path[i] != NULL)
				{
					free(path[i]);
					i++;
				}
				free(path);
				free(tmp_arg);
				return (arg);
			}
			else
			{
				free(arg);
				arg = tmp_arg;
			}
			i++;
		}
	}
	return NULL;
}


char *check_command(char *argv, char **path)
{
	char *tmp;
	char *true_path;
	char *probel;
	char *flags;

	probel = ft_strchr(argv, ' ');
	if (probel)
	{
		flags = ft_strdup(probel + 1);
		if (flags == NULL)
			return NULL;
		*probel = '\0';
		true_path = validation_check(argv, path);
		if (true_path)
		{
			tmp = ft_strjoin(true_path, " ");
			free(true_path);
			true_path = ft_strjoin(tmp, flags);
//			printf("%p\n", true_path);
			free(tmp);
			free(flags);
			return (true_path);
		}
		else
			return NULL;
	}
	else
	{
		true_path = validation_check(argv, path);
//		printf("%p\n", true_path);
		if (true_path == NULL)
			return NULL;
		else
			return (true_path);

	}
}

int check_arguments(int argc, char *argv[], char *envp[])
{
	char **paths_list;
	int i = 0;

	if (argc != 5 || access(argv[1], R_OK) != 0 || (access(argv[4], W_OK) != 0 && !access(argv[4], F_OK)))
	{
		perror("Error");
		exit(errno);
//		write (1, "ERROR: Invalid arguments", 24);
//		return 0;
	}
	paths_list = search_path(envp);
	if (paths_list == NULL)
	{
		free(paths_list);
		write (1, "Memory allocation error", 23);
		exit(1);
	}
	char *cmd1 = check_command(argv[2], paths_list);
	char *cmd2 = check_command(argv[3], paths_list);
	while(paths_list[i] != NULL)
	{
		free(paths_list[i]);
		i++;
	}
	free(paths_list);
//	printf("%s\n%s\n", a, b);
	if (!cmd1 || !cmd2)
	{
		free(cmd1);
		free(cmd2);
		return 0;
	}
	else
	{
		free(cmd1);
		free(cmd2);
		return 1;
	}
}
