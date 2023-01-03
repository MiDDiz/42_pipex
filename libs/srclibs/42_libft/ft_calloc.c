/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:13:00 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:13:00 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The C library function void *calloc(size_t nitems, size_t size) 
	allocates the requested memory and returns a pointer to it. 
	The difference in malloc and calloc is that malloc does not 
	set the memory to zero where as calloc sets allocated memory to zero.
*/
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*allocation;
	size_t	len;

	len = nitems * size;
	allocation = malloc(len);
	if (allocation == NULL)
		return (allocation);
	ft_bzero(allocation, len);
	return (allocation);
}
