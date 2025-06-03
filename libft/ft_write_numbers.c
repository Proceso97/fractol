/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:17:04 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/11/20 20:04:25 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *len)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*len)++;
		nb = -nb;
	}
	if (nb > 9)
	{
		if (ft_putnbr(nb / 10, len) == -1)
			return (-1);
	}
	if (ft_putchar('0' + (nb % 10), len) == -1)
		return (-1);
	return (0);
}

int	ft_unsigned_int(unsigned int n, int *len)
{
	if (n > 9)
	{
		if (ft_unsigned_int(n / 10, len) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0', len) == -1)
		return (-1);
	return (0);
}

int	ft_pointer(size_t ptr, int *len)
{
	char	*base;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		(*len) += 5;
		return (0);
	}
	base = "0123456789abcdef";
	if (ptr < 16)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		(*len) += 2;
	}
	if (ptr >= 16)
	{
		if (ft_pointer(ptr / 16, len) == -1)
			return (-1);
	}
	if (ft_putchar(base[ptr % 16], len) == -1)
		return (-1);
	return (0);
}

int	ft_hexadecimal(unsigned int x, int *len, char x_X)
{
	char	*base;

	if (x_X == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (x >= 16)
	{
		if (ft_hexadecimal(x / 16, len, x_X) == -1)
			return (-1);
	}
	if (ft_putchar(base[x % 16], len) == -1)
		return (-1);
	return (0);
}
