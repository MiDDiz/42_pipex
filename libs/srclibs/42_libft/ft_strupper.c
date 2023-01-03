/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:45:36 by jnaftana          #+#    #+#             */
/*   Updated: 2021/11/22 16:45:36 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Uppers a string, modifying it.
 * Dependencies: ft_toupper.c
*/
char	*ft_strupper(char *str)
{
	char	*str_ptr;

	str_ptr = str;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (str_ptr);
}
