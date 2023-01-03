/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:26:34 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:26:34 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The C library function char *strrchr(const char *str, int c) searches for 
	the last occurrence of the character c (an unsigned char) in the string 
	pointed to, by the argument str.
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_occurrence = (char *)str;
		str++;
	}
	if (*str == (char)c)
		last_occurrence = (char *)str;
	return (last_occurrence);
}
