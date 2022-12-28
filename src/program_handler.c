/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:34:10 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/28 15:12:49 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * This file contains the child managing logic 
*/

// Child 1
// We dont need to handle heap from parent ->
//https://stackoverflow.com/questions/5429141/what-happens-to-malloced-
//memory-after-exec-changes-the-program-image

// We dont need to read from pipe
// We dont need to read from std -> change stdin
// Close dupe fd
// Set output to input pipe -> close duplicated fd for pipe input;
// If execve returns -> perror: command executed error
int	input_program(t_pipexhandler *pipexhandler, char *envp[], int *pipes)
{
	int	in_fd;

	close(pipes[0]);
	in_fd = open_inputf(pipexhandler->input_f);
	if (in_fd < 0)
		return (-1);
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

int	exec_first_child(t_pipexhandler *pipexhandler, char *envp[], int *pipes)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		input_program(pipexhandler, envp, pipes);
		return (127);
	}
	if (pid < 0)
	{
		perror("Error on first fork");
		return (-2);
	}
	close(pipes[1]);
	waitpid(pid, &status, 0);
	return (0);
}

/*
 * Same as input but we need to redirect input from pipe and output to outfile. 
*/
int	output_program(t_pipexhandler *pipexhandler, char *envp[], int *pipes)
{
	int	out_fd;

	close(STDIN_FILENO);
	dup(pipes[0]);
	close(pipes[0]);
	out_fd = open_outputf(pipexhandler->output_f);
	if (out_fd < 0)
		return (-1);
	close(STDOUT_FILENO);
	dup(out_fd);
	close(out_fd);
	execve(pipexhandler->program2->path, pipexhandler->program2->argv, envp);
	perror(pipexhandler->program2->path);
	return (0);
}

int	exec_second_child(t_pipexhandler *pipexhandler, char *envp[], int *pipes)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		output_program(pipexhandler, envp, pipes);
		return (127);
	}
	if (pid < 0)
	{
		perror("Error on second fork");
		return (-3);
	}
	waitpid(pid, &status, 0);
	close(pipes[0]);
	return (0);
}
