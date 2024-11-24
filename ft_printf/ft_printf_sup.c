/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:37:02 by amsagman          #+#    #+#             */
/*   Updated: 2024/11/24 15:23:43 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_nbr(long c)
{
	int	len;
	int	tmp;

	len = 0;
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	if (c < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		c *= -1;
	}
	if (c >= 10)
	{
		tmp = ft_nbr(c / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[c % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_hex(unsigned long d, char b)
{
	int	len;
	int	tmp;

	len = 0;
	if (d >= 16)
	{
		tmp = ft_hex(d / 16, b);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (b == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[d % 16], 1) == -1)
			return (-1);
	}
	if (b == 'x')
	{
		if (write(1, &"0123456789abcdef"[d % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_point(unsigned long b)
{
	int len;
	int tmp;

	len = 0;
	if (!b)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	tmp = ft_hex(b, 'x');
	len += tmp;
	return (len + 1);
}
