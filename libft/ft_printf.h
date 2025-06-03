/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:46:03 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/11/20 20:12:42 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int	ft_flag(char c, va_list *args, int *i, int *len);
int	ft_putchar(char c, int *len);
int	ft_putnbr(int n, int *len);
int	ft_unsigned_int(unsigned int n, int *len);
int	ft_pointer(size_t ptr, int *len);
int	ft_hexadecimal(unsigned int x, int *len, char x_X);
int	ft_putstr(char *s, int *len);
int	ft_printf(char const *s, ...);
#endif
