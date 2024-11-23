/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:40:11 by amsagman          #+#    #+#             */
/*   Updated: 2024/11/13 14:40:12 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'd' || c == 'i')
		return (ft_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_nbr(va_arg(args, unsigned int)));
	else if (c == 's')
		return (ft_string(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg(args, unsigned long), 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		counter;
	int		tmp;

	counter = -1;
	len = 0;
	va_start(args, str);
	while (str[++counter] != '\0')
	{
		if (str[counter] == '%' && ft_check(str[counter + 1]))
		{
			tmp = ft_format(args, str[++counter]);
			if (tmp == -1)
				return (-1);
			len += tmp - 1;
		}
		else if (str[counter] == '%')
			continue ;
		else if (write(1, &str[counter], 1) == -1)
			return (-1);
		len++;
	}
	va_end(args);
	return (len);
}
