/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:23:43 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/16 10:49:13 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * Needs a command to search and a splitted PATH
 * with access we are able to find if we are able to 
 * execute a binary with that path. If we can, we have found or executable!
 * This method is not portable! -> slash hardcoded
*/

char	*search_from_env(char *cmd, char **splitted_path)
{
	char	*foopath;
	char	*pathname;
	char	*curr_path;

	pathname = NULL;
	curr_path = *splitted_path;
	while (curr_path)
	{
		foopath = ft_strjoin(curr_path, "/\0");
		pathname = ft_strjoin(foopath, cmd);
		free(foopath);
		if (access(pathname, X_OK) == 0)
			break;
		free(pathname);
		pathname = NULL;
		curr_path = *++splitted_path;
	}
	

	return (pathname);
}

/*
 * Gets PATH var from env, chops it and sends the command to be found and the treated PATH to fetch a command filepath
 * on success returns a command filepath
*/
char	*parse_from_env(char *command, char *envp[])
{
	// Find Path
	char	*foo;
	char	*path;
	char	**splitted_path;
	char	*pathname;

	foo = *envp;
	while (foo)
	{
		if (ft_strnstr(foo, "PATH=\0", 6))
			break;
		foo = *++envp;	// Go to next iteration
	}
	if (foo == NULL)	// If not found
		return (NULL);
	path = ft_substr(foo, 5, ft_strlen(foo) - 5);
	splitted_path = ft_split(path, ':');
	pathname = search_from_env(command, splitted_path);
	free(splitted_path);
	free(path);
	return (pathname);
}

/* 
 * Chops and parses program path and arguments
*/
programhandl_t	*parse_program(char *argv, char *envp[])
{
	programhandl_t	*program = malloc(sizeof(programhandl_t));
	program->argv = ft_split(argv, ' ');
	/* Program path should be first element of program argv */
	program->path = parse_from_env(program->argv[0], envp);
	return (program);
}

// Check for good arguments. Fill pseudoglobal handler.

int	parse_args(int argc, char* argv[], pipexhandler_t **p_handl, char *envp[])
{
	if (argc != 5)
	{
		// Maybe print error
		return (-1);
	}

	// We are generating pipex handler here so we need to make it a dinamically assinged pointer in order to make it escape this function scope.
	pipexhandler_t	*pipexhandler = malloc(sizeof(pipexhandler_t));
	if (pipexhandler == NULL)
	{
		// Probably print malloc malfuction.
		return (-1);
	}
	pipexhandler->input_f = argv[1];
	pipexhandler->output_f = argv[4];
	// We chop down program info on helper function and return a programhandler
	pipexhandler->program1 = parse_program(argv[2], envp);
	pipexhandler->program2 = parse_program(argv[3], envp);
	/*
		ft_printf("Program1 path: %s\n", pipexhandler->program1->argv[2]);
	*/
	// Asign curently generated handler to pseudoglobal handler. 
	*p_handl = pipexhandler;
	return (0);
}