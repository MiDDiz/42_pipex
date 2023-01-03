/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:55:57 by jnaftana          #+#    #+#             */
/*   Updated: 2022/07/18 11:39:46 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
 * Prints a char, then updates the number of characters printed.
*/
void	p_char(char c, size_t *ptr_n_printed)
{
	ft_putchar_fd(c, 1);
	*ptr_n_printed += 1;
}

/*
 * Prints a string, then updates the number of characters printed.
 * For NULL strings printf prints the sequence : "(null)"
*/
void	p_str(char *str, size_t *ptr_n_printed)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*ptr_n_printed += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*ptr_n_printed += ft_strlen(str);
}

void	p_int(int num, size_t *ptr_n_printed)
{
	char	*n_str;

	n_str = ft_itoa(num);
	ft_putstr_fd(n_str, 1);
	*ptr_n_printed += ft_strlen(n_str);
	free(n_str);
}
