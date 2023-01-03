/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:22:47 by jnaftana          #+#    #+#             */
/*   Updated: 2021/09/22 18:12:52 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *const_s)
{
	int		neg;
	int		res;
	char	*str;

	str = (char *)const_s;
	neg = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\v'
			|| *str == '\n' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		neg *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - '0';
		str++;
	}
	res *= neg;
	return (res);
}
