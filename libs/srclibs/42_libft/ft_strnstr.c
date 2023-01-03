/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:26:25 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:26:25 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
     The strnstr() function locates the	first occurrence of the	null-termi-
     nated string little in the	string big, where not more than	len characters
     are searched.  Characters that appear after a `\0'	character are not
     searched.
*/
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr_big;
	char	*ptr_little;

	if (!*little || big == little)
		return ((char *)big);
	while (*big && len)
	{
		if (*big == *little)
		{
			ptr_big = (char *)big;
			ptr_little = (char *)little;
			while (*ptr_little && (*ptr_little == *ptr_big))
			{
				ptr_little++;
				ptr_big++;
			}
			if ((*ptr_little == 0 )
				&& (ft_strlen(little) <= len))
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (NULL);
}
