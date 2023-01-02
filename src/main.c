/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:01 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/29 13:40:57 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * Handles parent logic for forking and generating pipes.
*/
int	start_execution(t_pipexhandler *pipexhandler, char *envp[])
{
	int		pipes[2];

	if (pipe(pipes))
	{
		perror("Error generating pipes");
		return (-1);
	}
	if (exec_first_child(pipexhandler, envp, pipes))
	{
		return (-10);
	}
	if (exec_second_child(pipexhandler, envp, pipes))
	{
		return (-20);
	}
	return (0);
}

// Pseudo global pipex handler
// File descriptors for out-in files
int	main(int argc, char *argv[], char *envp[])
{
	t_pipexhandler	*pipexhandler;

	if (argc != 5)
	{
		ft_printf("Unexpected argument count.\n");
		ft_printf("Ussage: ./pipex f_in command1 command2 f_out\n");
		return (0);
	}
	if (parse_args(argv, &pipexhandler, envp) < 0)
	{
		perror("Error while parsing arguments");
		if (pipexhandler == NULL)
			return (-1);
		cleanup(pipexhandler);
		return (-2);
	}
	if (start_execution(pipexhandler, envp))
	{
		cleanup(pipexhandler);
		return (127);
	}
	cleanup(pipexhandler);
	return (0);
}
