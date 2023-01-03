/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:15:41 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:27:08 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare_on_site(char *str, char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	if (*to_find)
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			if (compare_on_site(str, to_find))
			{
				return (str);
			}
		}
		str++;
	}
	return (0);
}
