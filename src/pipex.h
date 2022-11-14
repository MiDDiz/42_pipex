/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:13 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/14 13:09:00 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Lib includes

#include "../libs/srclibs/42_libft/libft.h"
#include "../libs/srclibs/ft_printf/includes/ft_printf.h"

// Standard includes

// strerror
#include <string.h>
// errno
#include <errno.h>
// open
#include <fcntl.h>
// perror
#include <stdio.h>


/*
 * Holds the info of each program.
 * argv is an array of char* that holds the same program plus each of its arguments.
 */
typedef struct programhandl_s
{
	char	*path;
	char	**argv;
} programhandl_t;

/*
 * pipexhandler has every information needes for pipex execution. 
*/
typedef struct pipexhandler_s
{
	char	*input_f;
	char	*output_f;
	programhandl_t	*program1;
	programhandl_t	*program2;
	
} pipexhandler_t;

/* Arg handler */
int	parse_args(int argc, char* argv[], pipexhandler_t **pipexhandler);

/*File handlers*/
int	open_outputf(char *path);
int	open_inputf(char *path);