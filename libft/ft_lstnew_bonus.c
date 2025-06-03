/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:28:24 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/10/18 19:22:57 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>

int main(void)
{
    char *str = "Hello, world!";

    // Crea un nuevo nodo de la lista con el contenido 'str'
    t_list *node = ft_lstnew(str);

    // Verifica si la creación del nodo fue exitosa
    if (node)
    {
        printf("Content: %s\n", (char *)node->content);
        printf("Next: %p\n", (void *)node->next);
    }

    // Libera la memoria del nodo
    free(node);
    return 0;
}
*/
