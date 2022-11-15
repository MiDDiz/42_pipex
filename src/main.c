/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:01 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/15 12:12:58 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void readfile(int fd)
{
	char buff;
	int a = 1;
	while(a)
	{
		a = read(fd,&buff, 1);
		ft_printf("%c", buff);
	}
}

int start_execution(pipexhandler_t *pipexhandler, char *envp[])
{
	pid_t pid;
	int pipes[2];
	int status;
	
	if (pipe(pipes))
	{
		// HANDLE ERROS
		return (-1);
	}


	pid = fork();
	if (pid == 0)
	{
		int in_fd;
		// Child
		// We dont need to handle heap from parent -> https://stackoverflow.com/questions/5429141/what-happens-to-malloced-memory-after-exec-changes-the-program-image
		// TODO check what happens when fd -1
		// close stdin and read from input file opened
		
		close(pipes[0]);
		in_fd = open_inputf(pipexhandler->input_f);

		close(STDIN_FILENO);
		dup(in_fd);
		close(in_fd);
		// close pipe input from here
		
		// Set output to input pipe
		close(STDOUT_FILENO);
		dup(pipes[1]);
		// close duplicated fd for pipe input;
		close(pipes[1]);
		// program will close stdout and stdin
		// execute first program
		int as;
		as = execve(pipexhandler->program1->argv[0], pipexhandler->program1->argv, envp);
		perror(strerror(errno));
	}
	// Parent
	if (pid < 0)
	{
		// error on fork
		return (-2);
	}
	// close output pipe on parent
	close(pipes[1]);
	// wait for first program
	waitpid(pid, &status, 0);

	
	pid = fork();
	if (pid == 0)
	{
		int out_fd;
		// assign input to output of pipe

		close(STDIN_FILENO);
		dup(pipes[0]);
		close(pipes[0]);
		out_fd = open_outputf(pipexhandler->output_f);
		/*if (out_fd < 0)
		{
			// CONSIDER OPENING FILES BEFORE TO CHECK FOR avalibity
			// consider using access syscall for checking existance
			// TODO clean pipexhandler
			// close in_fd if open
			// print error
			;
		}*/
		// Child
		// assign input to output of pipe

		// assign output to file output
		close(STDOUT_FILENO);
		dup(out_fd);
		close(out_fd);
		// execute second program
		int ret = execve(pipexhandler->program2->argv[0], pipexhandler->program2->argv, envp);
		ft_printf("path: %s argv: %s\n", pipexhandler->program2->path, pipexhandler->program2->argv);
		ft_printf("Ret value: %d\n", ret);
		perror(strerror(errno));
	}
	// Parent
	// cleanup
	waitpid(pid, &status, 0);

	close(pipes[0]);
	return (0);
}
/*
int main(int argc, char *argv[], char *envp[])
{
	// Pseudo global pipex handler
	// TODO: clean up pipexhandler heap.
	pipexhandler_t *pipexhandler;
	// File descriptors for out-in files

	// Check for good arguments. Fill pseudoglobal handler.
	if (parse_args(argc, argv, &pipexhandler) < 0)
	{
		perror("Error while parsing arguments");
		
		if (pipexhandler == NULL)
		{
			// TODO: clean pipexhandler
			// maybe print malloc error
			return (-1);
		}
		return (-2);
	}
	start_execution(pipexhandler, envp);
	return (0);
}
*/

/*
int main(int argc, char* argv[], char *envp[])
{
	int pid;
	int pipes[2];

	char *args[] = {
		argv[1], NULL
	};


	char *out_args[] = {
		argv[3], NULL
	};

	ft_printf("Arguments %d, 1: %s, 2: %s\n", argc, args[0], args[1]);
	pipe(pipes);
	
	//write(pipes[1], "test\0", 5);
	//close(pipes[1]);
	
	
	pid = fork();
	if (pid == 0)
	{
		// no lee
		close(pipes[0]);
		int fd = open(argv[2], O_RDONLY);


		close(STDIN_FILENO);
		dup(fd);
		close(fd);

		close(STDOUT_FILENO);
		dup(pipes[1]);
		close(pipes[1]);

		execve(args[0], args, envp);
		perror(strerror(errno));
	}
	// no escribe
	close(pipes[1]);
	int a = 0;
	waitpid(pid, &a, 0);
	
	//	char buff[5];
	//	int r = 1;
	//	while (r)
	//	{
	//		ft_printf("NR: ");
	//		r = read(pipes[0], buff, 5);
	//		write(STDOUT_FILENO, buff, r);
	//		ft_printf("\n");
	//	}
	
	pid = fork();
	if (pid == 0)
	{
		int fd;

		close(STDIN_FILENO);
		dup(pipes[0]);
		close(pipes[0]);
		
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);

		close(STDOUT_FILENO);
		dup(fd);
		close(fd);


		execve(out_args[0], out_args, envp);
		perror(strerror(errno));

	}
	waitpid(pid, &a, 0);
	close(pipes[0]);
}*/

int main(int argc, char* argv[], char *envp[])
{
	char **next;

	ft_printf("Argc: %d argv: %s\n", argc, argv[0]);
		next = envp;
	
	do
	{
		ft_printf("%s\n", *next);
		next++;
	} while (*next);
	
}