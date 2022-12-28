/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:13 by jnaftana          #+#    #+#             */
/*   Updated: 2022/12/28 14:46:43 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Standard includes

# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>


// Lib includes

# include "../libs/srclibs/42_libft/libft.h"
# include "../libs/srclibs/ft_printf/includes/ft_printf.h"

/*
 * Holds the info of each program. argv is an array of char* that holds 
 * the same program plus each of its arguments.
 */

typedef struct programhandl_s
{
	char	*path;
	char	**argv;
}	t_programhandl;

/*
 * pipexhandler has every information needes for pipex execution. 
*/

typedef struct pipexhandler_s
{
	char			*input_f;
	char			*output_f;
	t_programhandl	*program1;
	t_programhandl	*program2;
}	t_pipexhandler;

/* Program hander */
int		exec_second_child(t_pipexhandler *ph, char *envp[], int *pipes);
int		exec_first_child(t_pipexhandler *ph, char *envp[], int *pipes);

/* Arg handler */
int		parse_args(int argc, char *argv[], t_pipexhandler **ph, char *envp[]);
void	cleanup(t_pipexhandler *pipexhandler);

/*File handlers*/
int		open_outputf(char *path);
int		open_inputf(char *path);

#endif
