/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:16:37 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:16:37 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;

	if (!dest && !src)
		return (dest);
	ptr_dest = ((char *)dest);
	ptr_src = ((char *)src);
	if (ptr_dest > ptr_src)
		while (n--)
			*(ptr_dest + n) = *(ptr_src + n);
	else
		while (n--)
			*ptr_dest++ = *ptr_src++;
	return (dest);
}
