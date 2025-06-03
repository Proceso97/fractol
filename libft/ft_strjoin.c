/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:03:08 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/10/14 16:40:17 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s1 || !s2)
		return (NULL);
	if (!dst)
		return (NULL);
	ft_memmove((void *)dst, (void *)s1, len1);
	ft_memmove((void *)(dst + len1), (void *)s2, len2);
	dst[len1 + len2] = '\0';
	return (dst);
}
