/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:45:26 by jnaftana          #+#    #+#             */
/*   Updated: 2022/07/18 11:29:53 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(char const *s, ...);
void	printf_handler(const char *s, va_list arg, size_t *n_prt, size_t n_arg);
size_t	get_num_args(char const *str);
void	args_handler(char arg_type, va_list v_args, size_t *ptr_n_printed);
void	p_char(char c, size_t *ptr_n_printed);
void	p_str(char *str, size_t *ptr_n_printed);
void	p_int(int num, size_t *ptr_n_printed);
void	p_uint(unsigned int num, size_t *ptr_n_printed);
void	p_hex(size_t num, size_t *ptr_n_printed);
void	p_hexup(size_t num, size_t *ptr_n_printed);
void	p_point(size_t num, size_t *ptr_n_printed);
int		is_arg(char a);
#endif