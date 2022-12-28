/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:23:43 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/28 15:14:16 by jnaftana         ###   ########.fr       */
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
			break ;
		free(pathname);
		pathname = NULL;
		curr_path = *++splitted_path;
	}
	return (pathname);
}

/*
 * Gets PATH var from env, chops it and sends the command to be found 
 * and the treated PATH to fetch a command filepath
 * on success returns a command filepath
*/
char	*parse_from_env(char *command, char *envp[])
{
	char	*foo;
	char	*path;
	char	**splitted_path;
	char	*pathname;
	int		i;

	foo = *envp;
	while (foo)
	{
		if (ft_strnstr(foo, "PATH=\0", 6))
			break ;
		foo = *++envp;
	}
	if (foo == NULL)
		return (NULL);
	path = ft_substr(foo, 5, ft_strlen(foo) - 5);
	splitted_path = ft_split(path, ':');
	pathname = search_from_env(command, splitted_path);
	i = 0;
	while (splitted_path[i])
		free(splitted_path[i++]);
	free(splitted_path);
	free(path);
	return (pathname);
}

/* 
 * Chops and parses program path and arguments
*/
t_programhandl	*parse_program(char *argv, char *envp[])
{
	t_programhandl	*program;

	program = malloc(sizeof(t_pipexhandler));
	program->argv = ft_split(argv, ' ');
	program->path = parse_from_env(program->argv[0], envp);
	return (program);
}

// Check for good arguments. Fill pseudoglobal handler.
// We are generating pipex handler here so we need to make it a dinamically 
// assinged pointer in order to make it escape this function scope.
// We chop down program info on helper function and return a programhandler

int	parse_args(int argc, char *argv[], t_pipexhandler **p_handl, char *envp[])
{
	t_pipexhandler	*pipexhandler;

	if (argc != 5)
		return (-1);
	pipexhandler = malloc(sizeof(t_pipexhandler));
	if (pipexhandler == NULL)
	{
		perror("Malloc error");
		return (-1);
	}
	pipexhandler->input_f = argv[1];
	pipexhandler->output_f = argv[4];
	pipexhandler->program1 = parse_program(argv[2], envp);
	pipexhandler->program2 = parse_program(argv[3], envp);
	*p_handl = pipexhandler;
	return (0);
}

/* If we have malloc'ed memory -> free it*/
void	cleanup(t_pipexhandler *pipexhandler)
{
	int	i;

	if (pipexhandler->program1->path)
		free(pipexhandler->program1->path);
	if (pipexhandler->program2->path)
		free(pipexhandler->program2->path);
	if (pipexhandler->program1->argv)
	{
		i = 0;
		while (pipexhandler->program1->argv[i])
			free(pipexhandler->program1->argv[i++]);
		free(pipexhandler->program1->argv);
	}
	if (pipexhandler->program2->argv)
	{
		i = 0;
		while (pipexhandler->program2->argv[i])
			free(pipexhandler->program2->argv[i++]);
		free(pipexhandler->program2->argv);
	}
	free(pipexhandler->program1);
	free(pipexhandler->program2);
	free(pipexhandler);
}
