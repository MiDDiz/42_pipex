/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:13:38 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:13:38 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

/*
 * We need to cat with size + 2 in order to accomodate space for
 * the new character and the null terminator of strlcat ^_^.
 * Dependencies: ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_calloc.c ft_bzero.c
*/

static void	ft_itoa_rec(int n, char *str)
{
	char	ch;

	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		ch = '-';
		ft_strlcat(str, &ch, ft_strlen(str) + 2);
		n = -n;
	}
	if (n >= 10)
	{
		ft_itoa_rec(n / 10, str);
		n = n % 10;
	}
	if (n < 10)
	{
		ch = (char)(n + 48);
		ft_strlcat(str, &ch, ft_strlen(str) + 2);
	}
}

static int	check_size(int n)
{
	int	size;

	size = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = ft_calloc(check_size(n) + 1, 1);
	if (!str)
		return (NULL);
	ft_itoa_rec(n, str);
	return (str);
}
