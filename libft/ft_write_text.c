/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:17:02 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/11/15 18:31:39 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *len)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}

int	ft_putstr(char	*s, int	*len)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		(*len) += 6;
		return (0);
	}
	while (s[i])
	{
		if (ft_putchar (s[i], len) == -1)
			return (-1);
		i++;
	}
	return (0);
}
