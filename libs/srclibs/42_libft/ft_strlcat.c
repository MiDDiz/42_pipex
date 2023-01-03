/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:51:47 by jnaftana          #+#    #+#             */
/*   Updated: 2021/11/22 18:42:37 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Dependencies: ft_strlen.c
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_n;
	size_t	src_n;
	size_t	i;

	dst_n = ft_strlen(dst);
	src_n = ft_strlen(src);
	i = 0;
	if (dstsize <= dst_n)
		return (dstsize + src_n);
	if (dstsize > (dst_n + 1))
	{
		while (src[i] != '\0' && (dst_n + 1 + i) < dstsize)
		{
			dst[dst_n + i] = src[i];
			i++;
		}
	}
	dst[dst_n + i] = '\0';
	return (src_n + dst_n);
}
