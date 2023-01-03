/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:22:09 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:16:10 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!dst && !src)
		return (dst);
	ptr_dst = ((unsigned char *)dst);
	ptr_src = ((unsigned char *)src);
	while (n-- > 0)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
