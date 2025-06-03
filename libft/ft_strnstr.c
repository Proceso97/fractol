/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:59:24 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/10/14 17:42:27 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	value;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	value = len;
	if (len > ft_strlen(haystack))
		value = ft_strlen(haystack);
	while ((i + ft_strlen(needle)) <= value)
	{
		c = 0;
		while (haystack[i + c] == needle[c] && needle[c])
			c++;
		if (!needle[c] && haystack[i + c -1] == needle[c -1])
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
