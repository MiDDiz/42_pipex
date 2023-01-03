/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:14:05 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:14:05 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	char	*str;

	str = (char *)ptr;
	while (n--)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
