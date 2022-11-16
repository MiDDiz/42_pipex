/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:01 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/16 10:47:27 by jnaftana         ###   ########.fr       */
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

// We dont need to read from pipe
// We dont need to read from std -> change stdin
// Close dupe fd
// Set output to input pipe -> close duplicated fd for pipe input;
// If execve returns -> perror: command executed error
int input_program(pipexhandler_t *pipexhandler, char *envp[], int *pipes)
{
	int in_fd;

	close(pipes[0]);
	in_fd = open_inputf(pipexhandler->input_f);	// We open the input file
	if (in_fd < 0)
	{
		perror(pipexhandler->input_f);
		return (-1);
	}
	close(STDIN_FILENO);
	dup(in_fd);				
	close(in_fd);			
	close(STDOUT_FILENO);		
	dup(pipes[1]);
	close(pipes[1]);		
	execve(pipexhandler->program1->path, pipexhandler->program1->argv, envp);
	perror(pipexhandler->program1->path);
	return (0);
}

/*
 * Same as input but we need to redirect input from pipe and output to outfile. 
*/
int output_program(pipexhandler_t *pipexhandler, char *envp[], int *pipes)
{
	int out_fd;

	close(STDIN_FILENO);
	dup(pipes[0]);
	close(pipes[0]);
	out_fd = open_outputf(pipexhandler->output_f);
	if (out_fd < 0)
	{
		perror(pipexhandler->output_f);
		return (-1);
	}
	close(STDOUT_FILENO);
	dup(out_fd);
	close(out_fd);
	execve(pipexhandler->program2->path, pipexhandler->program2->argv, envp);
	perror(pipexhandler->program2->path);
	return (0);
}

/* If we have malloc'ed memory -> free it*/
void	cleanup(pipexhandler_t *pipexhandler)
{
	if (pipexhandler->program1->path)
		free(pipexhandler->program1->path);
	if (pipexhandler->program2->path)
		free(pipexhandler->program2->path);
	if (pipexhandler->program1->argv)
		free(pipexhandler->program1->argv);
	if (pipexhandler->program2->argv)
		free(pipexhandler->program2->argv);
	free(pipexhandler->program1);
	free(pipexhandler->program2);
	free(pipexhandler);
}


/*
 * Handles parent logic for forking and generating pipes.
*/
int	start_execution(pipexhandler_t *pipexhandler, char *envp[])
{
	pid_t	pid;
	int		pipes[2];
	int		status;
	
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

// Pseudo global pipex handler
// File descriptors for out-in files
int	main(int argc, char *argv[], char *envp[])
{
	
	pipexhandler_t	*pipexhandler;
	
	if (parse_args(argc, argv, &pipexhandler, envp) < 0)
	{
		perror("Error while parsing arguments");
		
		if (pipexhandler == NULL)
		{
			ft_printf("FATAL ERROR: Error while generating pipexhandler\n");
			return (-1);
		}
		return (-2);
	}
	start_execution(pipexhandler, envp);
	cleanup(pipexhandler);
	return (0);
}
