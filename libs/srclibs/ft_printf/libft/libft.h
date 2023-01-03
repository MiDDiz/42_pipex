/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:58:33 by jnaftana          #+#    #+#             */
/*   Updated: 2021/10/02 10:58:33 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
void		ft_bzero(void *addr, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_itoa(int n);
void		ft_putchar_fd(char s, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_toupper(int str);
void		*ft_calloc(size_t nitems, size_t size);
char		*ft_utoa(unsigned int n);
char		*ft_hextoa(size_t num);
char		*ft_strupper(char *str);
#endif
