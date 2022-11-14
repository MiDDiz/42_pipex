/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:10:43 by jnaftana          #+#    #+#             */
/*   Updated: 2022/11/14 13:22:00 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_inputf(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0) 
	{
		perror(strerror(errno));
	}
	ft_printf("Opening input %s at fd: %d\n", path, fd);
	return (fd);
}

int	open_outputf(char *path)
{
	int fd;

	fd = open(path,O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd <= 0) 
	{
		perror(strerror(errno));
		perror("Unable to create file");
	}
	ft_printf("Opening output %s at fd: %d\n", path, fd);
	return (fd);
}