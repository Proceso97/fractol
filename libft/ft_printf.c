/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:12:05 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/05/13 22:24:00 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg_end(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	ft_flag(char c, va_list *args, int *i, int *len)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar(va_arg(*args, int), len);
	else if (c == 's')
		res = ft_putstr(va_arg(*args, char *), len);
	else if (c == 'p')
		res = ft_pointer(va_arg(*args, size_t), len);
	else if (c == 'd' || c == 'i')
		res = ft_putnbr(va_arg(*args, int), len);
	else if (c == 'u')
		res = ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (c == 'x')
		res = ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (c == 'X')
		res = ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (c == '%')
		res = ft_putchar('%', len);
	else
		(*i)--;
	if (res == -1)
		return (-1);
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (ft_flag(s[i], &args, &i, &len) == -1)
				return (ft_arg_end(&args));
		}
		else
		{
			if (ft_putchar((char)s[i], &len) == -1)
				return (ft_arg_end(&args));
		}
		i++;
	}
	va_end(args);
	return (len);
}
