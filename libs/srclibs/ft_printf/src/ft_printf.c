/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:34:45 by jnaftana          #+#    #+#             */
/*   Updated: 2022/07/18 11:39:20 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
 * This is the main function. The starting point of ft_printf.
 * We use this to make all the calls to the methods that compose 
 * the functionality of the main function.
 * 
 *  get_num_args -> Number of valid '%arg'  in order to initialize v_args
 *  printf_handler -> main functionality
 * 
 *  return value: the number of characters printed.
*/

int	ft_printf(const char *str, ...)
{
	size_t	size;
	va_list	v_args;
	size_t	n_print_char;

	n_print_char = 0;
	size = get_num_args(str);
	va_start(v_args, str);
	printf_handler(str, v_args, &n_print_char, size);
	va_end(v_args);
	return (n_print_char);
}

/*
 * This function is used to get the total ammount of valid '%arg' occurences 
 */

size_t	get_num_args(char const *str)
{
	char	*ptr_str;
	size_t	num_args;

	ptr_str = (char *)str;
	num_args = 0;
	while (*ptr_str)
	{
		if (*ptr_str == '%' && is_arg(*(ptr_str + 1)))
		{
			num_args++;
		}
		ptr_str++;
	}
	return (num_args);
}

/*
 * This is the main functionality function.
 * It iterates for the whole str passed finding valid '%args' occurences.
 * If not found we print the character normally.
 * If we found an arg, we pass everything to a args handler function.
 * 
 * Arguments: 
 * 		str -> the main string
 * 		v_args -> the list of arguments passed
 * 		n_args -> the number of arguments passed (maybe unnecesary)
 * 		ptr_n_printd -> ptr to the size_t which stores the num of chars printed.
 * 		
*/

void	printf_handler(const char *s, va_list arg, size_t *n_prt, size_t n_arg)
{
	char	*ptr_str;

	ptr_str = (char *)s;
	while (*ptr_str)
	{
		if (*ptr_str == '%' && is_arg(*(ptr_str + 1)))
		{
			ptr_str++;
			n_arg--;
			args_handler(*ptr_str, arg, n_prt);
			ptr_str++;
		}
		else
		{
			ft_putchar_fd(*ptr_str, 1);
			*n_prt += 1;
			ptr_str++;
		}
	}
}

/*
 * Control what type of printing is necesary
*/

void	args_handler(char arg_type, va_list v_args, size_t *ptr_n_printed)
{
	if (arg_type == 'c')
		p_char((char) va_arg(v_args, int), ptr_n_printed);
	else if (arg_type == 's')
		p_str(va_arg(v_args, char *), ptr_n_printed);
	else if (arg_type == 'd' || arg_type == 'i')
		p_int(va_arg(v_args, int), ptr_n_printed);
	else if (arg_type == 'u')
		p_uint(va_arg(v_args, unsigned int), ptr_n_printed);
	else if (arg_type == 'x')
		p_hex(va_arg(v_args, unsigned int), ptr_n_printed);
	else if (arg_type == 'X')
		p_hexup(va_arg(v_args, unsigned int), ptr_n_printed);
	else if (arg_type == 'p')
		p_point((size_t) va_arg(v_args, void *), ptr_n_printed);
	else if (arg_type == '%')
		p_char('%', ptr_n_printed);
}

/*
	Check if char given is an argument
*/

int	is_arg(char a)
{
	return ((a == 'c') || (a == 's') || (a == 'p') || \
			(a == 'd') || (a == 'i') || (a == 'u') || \
			(a == 'x') || (a == 'X') || (a == '%'));
}
