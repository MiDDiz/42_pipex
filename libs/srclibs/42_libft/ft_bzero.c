/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:22:52 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:12:55 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *addr, size_t len)
{
	char	*ptr_cast;

	ptr_cast = (char *)addr;
	while (len--)
		*ptr_cast++ = 0;
}
