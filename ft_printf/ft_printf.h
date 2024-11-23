/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:40:38 by amsagman          #+#    #+#             */
/*   Updated: 2024/11/21 14:37:24 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_nbr(int c);
int	ft_putchar(char c);
int	ft_string(char *str);
int	ft_hex(unsigned int d, char b);
int	ft_point(unsigned long b, int i);

#endif