/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:01 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/15 12:42:05 by jnaftana         ###   ########.fr       */
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


// Child 1
// We dont need to handle heap from parent -> https://stackoverflow.com/questions/5429141/what-happens-to-malloced-memory-after-exec-changes-the-program-image
// TODO check what happens when fd -1

int input_program(pipexhandler_t *pipexhandler, char *envp[], int *pipes)
{
	int in_fd;

	close(pipes[0]);	// We dont need to read from pipe
	in_fd = open_inputf(pipexhandler->input_f);	// We open the input file
	if (in_fd < 0)
	{
		perror(pipexhandler->input_f);
		return (-1);
	}
	close(STDIN_FILENO);	// We dont need to read from std
	dup(in_fd);				// Now our stdin is the file
	close(in_fd);			// Close dupe fd
	close(STDOUT_FILENO);		// Set output to input pipe
	dup(pipes[1]);
	close(pipes[1]);		// close duplicated fd for pipe input;
	execve(pipexhandler->program1->argv[0], pipexhandler->program1->argv, envp);
	perror(pipexhandler->program1->argv[0]);	// If execve returns -> perror: command executed error
	return (0);
}

int output_program(pipexhandler_t *pipexhandler, char *envp[], int *pipes)
{
	int out_fd;

	close(STDIN_FILENO);	// assign input to output of pipe
	dup(pipes[0]);
	close(pipes[0]);
	out_fd = open_outputf(pipexhandler->output_f);
	if (out_fd < 0)
	{
		perror(pipexhandler->output_f);
		return (-1);
	}
	close(STDOUT_FILENO);	// Assign output to file output
	dup(out_fd);
	close(out_fd);
	execve(pipexhandler->program2->argv[0], pipexhandler->program2->argv, envp);
	perror(pipexhandler->program2->argv[0]);
	return (0);
}

int start_execution(pipexhandler_t *pipexhandler, char *envp[])
{
	pid_t pid;
	int pipes[2];
	int status;
	
	if (pipe(pipes))
	{
		perror("Error generating pipes");
		return (-1);
	}
	pid = fork();	// Fork first child
	if (pid == 0)	// If child
	{
		input_program(pipexhandler, envp, pipes);
	}
	if (pid < 0)	// Parent
	{
		perror("Error on first fork");
		return (-2);	// error on fork
	}
	close(pipes[1]);		// close output pipe on parent
	waitpid(pid, &status, 0);	// wait for first program
	pid = fork();		// Fork second child
	if (pid == 0)
	{
		output_program(pipexhandler, envp, pipes);
	}
	if (pid < 0)	// Parent
	{
		perror("Error on second fork");
		return (-3);	// error on fork
	}
	waitpid(pid, &status, 0);
	close(pipes[0]);
	return (0);
}

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