/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:40:11 by amsagman          #+#    #+#             */
/*   Updated: 2024/11/26 17:58:22 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

static int	ft_format(va_list args, char c)
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
		return (ft_point(va_arg(args, void *)));
	else
		return (-1);
}

static int	ft_support(const char *str, va_list args, int *len)
{	
	int	tmp ;
	int	count;

	count = -1;
	while (str[++count] != '\0')
	{
		if (str[count] == '%' && !ft_check(str[count + 1]))
			return (-1);
		if (str[count] == '%' && ft_check(str[count + 1]))
		{
			tmp = ft_format(args, str[++count]);
			if (tmp == -1)
				return (-1);
			(*len) += tmp - 1;
		}
		else if (write(1, &str[count], 1) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	len = 0;
	va_start(args, str);
	if ((ft_support(str, args, &len)) == -1)
		return (-1);
	return (va_end(args), len);
}
