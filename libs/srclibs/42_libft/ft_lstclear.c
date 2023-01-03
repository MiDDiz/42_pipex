/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:10:42 by jnaftana          #+#    #+#             */
/*   Updated: 2021/10/02 10:56:53 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swap;

	if (!*lst)
		return ;
	while (*lst)
	{
		swap = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = swap;
	}
}
