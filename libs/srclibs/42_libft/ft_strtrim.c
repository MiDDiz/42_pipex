/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:27:20 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:27:20 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, (int)*(s1 + start)) && *(s1 + start))
		start++;
	if (!*(s1 + start))
		return (ft_strdup(""));
	while (ft_strchr(set, (int)*(s1 + len - 1 - end)) && *(s1 + len - 1 - end))
		end++;
	return (ft_substr(s1, start, len - start - end));
}
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_str;
	char	*new_str;
	size_t	size_str;

	if (!s1 || !set)
		return (NULL);
	ptr_str = (char *)s1;
	if (!*s1)
		return (ft_strdup(ptr_str));
	while (*ptr_str && ft_strchr(set, *ptr_str))
		ptr_str++;
	size_str = ft_strlen(ptr_str);
	while (size_str && ft_strchr(set, ptr_str[size_str]))
		size_str--;
	new_str = ft_substr(ptr_str, 0, size_str + 1);
	return (new_str);
}
*/