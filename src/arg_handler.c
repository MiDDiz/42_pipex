/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:23:43 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/14 12:01:33 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* 
 * Chops and parses program path and arguments
*/
programhandl_t *parse_program(char *argv)
{
	programhandl_t	*program = malloc(sizeof(programhandl_t));
	program->argv = ft_split(argv, ' ');
	/* Program path should be first element of program argv */
	program->path = program->argv[0];
	
	return (program);
}

int	parse_args(int argc, char* argv[], pipexhandler_t **p_handl)
{
	if (argc != 5)
	{
		// Maybe print error
		return (-1);
	}

	/*
		ft_printf("Argument 0:%s\n", ft_strtrim(argv[0], " "));
		ft_printf("Argument 1:%s\n", ft_strtrim(argv[1], " "));
		ft_printf("Argument 2:%s\n", ft_strtrim(argv[2], " "));
		ft_printf("Argument 3:%s\n", ft_strtrim(argv[3], " "));
		ft_printf("Argument 4:%s\n", ft_strtrim(argv[4], " "));
	*/

	// We are generating pipex handler here so we need to make it a dinamically assinged pointer in order to make it escape this function scope.
	pipexhandler_t *pipexhandler = malloc(sizeof(pipexhandler_t));
	if (pipexhandler == NULL)
	{
		// Probably print malloc malfuction.
		return (-1);
	}
	pipexhandler->input_f = argv[1];
	pipexhandler->output_f = argv[4];
	// We chop down program info on helper function and return a programhandler
	pipexhandler->program1 = parse_program(argv[2]);
	pipexhandler->program2 = parse_program(argv[3]);
	/*
		ft_printf("Program1 path: %s\n", pipexhandler->program1->argv[2]);
	*/
	// Asign curently generated handler to pseudoglobal handler. 
	*p_handl = pipexhandler;
	return (0);
}