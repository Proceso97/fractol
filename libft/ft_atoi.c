/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:05:04 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/10/14 17:32:34 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	printf("%d\n", ft_atoi("12345"));	// Imprime 12345
	printf("%d\n", atoi("12345"));
	printf("%d\n", ft_atoi("-98765"));// Imprime -98765
	printf("%d\n", atoi("-98765"));	
	printf("%d\n", ft_atoi("  -42mi amore12412"));// Imprime -42
	printf("%d\n", atoi("  +42mi amore12412"));
	printf("%d\n", ft_atoi("2147483647")); // Puede causar overflow en
					       //  implementaciones que no controlen 
					       //  el límite de int
	printf("%d\n", atoi("2147483647"));
	printf("%d\n", ft_atoi("-214748364899")); // Puede causar overflow
	printf("%d\n", atoi("-214748364899"));
	return 0;
}*/
