/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:01 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/14 13:57:12 by jnaftana         ###   ########.fr       */
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

int start_execution(pipexhandler_t *pipexhandler)
{
	pid_t pid;
	int in_fd, out_fd;
	int pipes[2];
	int status;
	
	if (pipe(pipes))
	{
		// HANDLE ERROS
		return (-1);
	}
	// close stdin
	in_fd = open_inputf(pipexhandler->input_f);
	//readfile(in_fd);
	pid = fork();
	if (pid == 0)
	{
		// Child
		// We dont need to handle heap from parent -> https://stackoverflow.com/questions/5429141/what-happens-to-malloced-memory-after-exec-changes-the-program-image
		// TODO check what happens when fd -1
		// close stdin and read from input file opened
		close(STDIN_FILENO);
		dup(in_fd);
		close(in_fd);
		// close pipe input from here
		close(pipes[0]);
		// Set output to input pipe
		close(STDOUT_FILENO);
		dup(pipes[1]);
		// close duplicated fd for pipe input;
		close(pipes[1]);
		// program will close stdout and stdin
		// execute first program
		int as;
		as = execve(pipexhandler->program1->path, pipexhandler->program1->argv, NULL);
		ft_printf("Return: %d", as);
	}
	// Parent
	if (pid < 0)
	{
		// error on fork
		return (-2);
	}
	// close input on parent
	close(in_fd);
	// close output pipe on parent
	close(pipes[1]);
	// wait for first program
	waitpid(pid, &status, 0);

	readfile(pipes[0]);
	out_fd = open_outputf(pipexhandler->output_f);
	if (out_fd < 0)
	{
		// CONSIDER OPENING FILES BEFORE TO CHECK FOR avalibity
		// consider using access syscall for checking existance
		// TODO clean pipexhandler
		// close in_fd if open
		// print error
	}
	pid = fork();
	if (pid == 0)
	{
		// Child
		// assign input to output of pipe
		close(STDIN_FILENO);
		dup(pipes[0]);
		close(pipes[0]);
		// assign output to file output
		close(STDOUT_FILENO);
		dup(out_fd);
		close(out_fd);
		// execute second program
		execve(pipexhandler->program2->path, pipexhandler->program2->argv, NULL);
	}
	// Parent
	// cleanup
	close(pipes[0]);
	close(out_fd);
	return (0);
}

int main(int argc, char *argv[])
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
	start_execution(pipexhandler);
	return (0);
}
