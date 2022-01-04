//
// Created by Claribel Stefany on 12/17/21.
//

# include "pipex.h"

//void ft_dup()

int main(int argc, char *argv[], char *envp[])
{

//	int c = errors();
	if (!check_arguments(argc, argv, envp))
	{
		return 0;
	}
	else
		printf("ok");
	return 0;


	//	if (access(argv[4], F_OK) != 0)
//		fd_output = open(argv[4], O_CREAT, 0777);        // todo открывать и создавать файлы в основной функции
//	fd_input = open(argv[1], O_RDONLY);

}

//int pipex()