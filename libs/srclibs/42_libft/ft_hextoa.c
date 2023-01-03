/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:24:19 by jnaftana          #+#    #+#             */
/*   Updated: 2021/11/22 13:24:19 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Dependencies: ft_strlcat.c ft_strlen.c ft_calloc.c ft_bzero.c
 */

static void	ft_hextoa_rec(size_t num, char *str, char *dict)
{
	if (num >= 16)
	{
		ft_hextoa_rec(num / 16, str, dict);
		num = num % 16;
	}
	if (num < 16)
	{
		ft_strlcat(str, &(dict[num]), ft_strlen(str) + 2);
	}
}

static int	check_size(size_t num)
{
	int	size;

	size = 1;
	while (num >= 16)
	{
		num = num / 16;
		size++;
	}
	return (size);
}

char	*ft_hextoa(size_t num)
{
	char	*dict;
	char	*str;

	dict = "0123456789abcdef";
	str = ft_calloc(check_size(num) + 1, 1);
	if (!str)
		return (NULL);
	ft_hextoa_rec(num, str, dict);
	return (str);
}
