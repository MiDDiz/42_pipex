/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:46:03 by jnaftana          #+#    #+#             */
/*   Updated: 2021/11/16 17:46:03 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Dependencies: ft_strlcat.c ft_strlen.c ft_calloc.c ft_bzero.c
 */
#include "libft.h"

static void	ft_utoa_rec(unsigned int n, char *str)
{
	char	c;

	if (n >= 10)
	{
		ft_utoa_rec(n / 10, str);
		n = n % 10;
	}
	if (n < 10)
	{
		c = (char)(n + 48);
		ft_strlcat(str, &c, ft_strlen(str) + 2);
	}
}

static int	check_size(unsigned int n)
{
	int	size;

	size = 1;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;

	str = ft_calloc(check_size(n) + 1, 1);
	if (!str)
		return (NULL);
	ft_utoa_rec(n, str);
	return (str);
}
