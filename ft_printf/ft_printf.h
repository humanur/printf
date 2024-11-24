/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:40:38 by amsagman          #+#    #+#             */
/*   Updated: 2024/11/24 15:03:23 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_nbr(long c);
int	ft_putchar(char c);
int	ft_string(char *str);
int	ft_hex(unsigned long d, char b);
int	ft_point(unsigned long b);

#endif