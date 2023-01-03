/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:22:37 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:22:37 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
       The strdup() function returns a pointer to a new string which is
       a duplicate of the string s.  Memory for the new string is
       obtained with malloc(3), and can be freed with free(3).
*/
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*output_str;
	int		i;

	output_str = (char *) malloc(sizeof (*src) * (ft_strlen(src) + 1));
	if (!output_str)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		output_str[i] = src[i];
		i++;
	}
	output_str[i] = '\0';
	return (output_str);
}
