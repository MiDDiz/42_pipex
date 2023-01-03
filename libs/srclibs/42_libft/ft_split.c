/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:17:02 by jnaftana          #+#    #+#             */
/*   Updated: 2021/10/18 19:03:44 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wcount(char *str, char c)
{
	size_t	wcount;

	wcount = 0;
	if (!*str)
		return (0);
	if (*str != c && *(str + 1))
		wcount = 1;
	while (*(str + 1))
	{
		if (*str == c && *(str + 1) != c && *(str + 1) != '\0')
			wcount++;
		str++;
	}
	return (wcount);
}

static void	ft_splitter(char **table, char const *str, char c, size_t c_word)
{
	int	i_str;
	int	i_word;
	int	i_char;
	int	i_new_str;

	i_new_str = 0;
	i_str = 0;
	while (c_word--)
	{
		while (str[i_str] == c && str[i_str])
			i_str++;
		i_word = i_str;
		while (str[i_str] != c && str[i_str])
			i_str++;
		table[i_new_str] = (char *)malloc(sizeof(char) * (i_str - i_word + 1));
		i_char = 0;
		while (i_word < i_str)
			table[i_new_str][i_char++] = str[i_word++];
		table[i_new_str][i_char] = '\0';
		i_new_str++;
	}
	table[i_new_str] = NULL;
}

char	**ft_split(const char *str, char s)
{
	char	**str_table;
	size_t	c_words;

	c_words = ft_wcount((char *)str, s);
	str_table = (char **)malloc(sizeof(char *) * (c_words + 1));
	if (!str_table)
		return (NULL);
	ft_splitter(str_table, str, s, c_words);
	return (str_table);
}
