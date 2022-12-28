/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:01 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/28 14:57:14 by jnaftana         ###   ########.fr       */
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
	if (start_execution(pipexhandler, envp))
	{
		return (127);
		cleanup(pipexhandler);
	}
	cleanup(pipexhandler);
	return (0);
}
