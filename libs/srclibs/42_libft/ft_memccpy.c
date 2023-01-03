/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:54:12 by middiz            #+#    #+#             */
/*   Updated: 2021/09/22 18:13:55 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	if (!dest && !src)
		return (dest);
	ptr_src = (unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	while (n--)
	{
		if (*ptr_src == (unsigned char)c)
		{
			*ptr_dest++ = *ptr_src;
			return (ptr_dest++);
		}
		*ptr_dest++ = *ptr_src;
		ptr_src++;
	}
	return (NULL);
}
