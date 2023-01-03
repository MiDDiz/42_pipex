/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:27:51 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:18:36 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *addr, int c, size_t len)
{
	char	*ptr;

	ptr = ((char *)addr);
	while (len--)
		*ptr++ = c;
	return (addr);
}
