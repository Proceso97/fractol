/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:45:54 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/10/23 20:32:36 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*new;
	void	*content;

	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		element = ft_lstnew(content);
		if (!element)
		{
			free(content);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, element);
		lst = lst -> next;
	}
	return (new);
}
/*
#include <stdio.h>
#include <stdlib.h>

// Función para transformar el contenido del nodo
void *square(void *content) {
    int *result = malloc(sizeof(int));
    if (result) {
        *result = (*(int *)content) * (*(int *)content);
    }
    return result;
}

// Función para liberar el contenido del nodo
void del(void *content) {
    free(content);  // Liberar la memoria ocupada por el contenido
}

// Función para imprimir el contenido del nodo
void print_content(void *content) {
    if (content) {
        printf("%d\n", *(int *)content);
    }
}

// Función principal para probar ft_lstmap
int main() {
    t_list *list = NULL; // Inicializamos la lista como vacía

    // Crear algunos nodos
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    if (!data1 || !data2 || !data3) {
        perror("Failed to allocate memory");
        return 1; // Manejo de errores en la asignación de memoria
    }

    *data1 = 1;
    *data2 = 2;
    *data3 = 3;

    // Añadir nodos a la lista
    ft_lstadd_back(&list, ft_lstnew(data1));
    ft_lstadd_back(&list, ft_lstnew(data2));
    ft_lstadd_back(&list, ft_lstnew(data3));

    // Imprimir contenido de la lista original
    printf("Contenido de la lista original:\n");
    ft_lstiter(list, print_content);

    // Aplicar ft_lstmap para crear una nueva lista
    t_list *new_list = ft_lstmap(list, square, del);

    // Imprimir contenido de la nueva lista
    printf("Contenido de la nueva lista (cuadrados):\n");
    ft_lstiter(new_list, print_content);

    // Limpiar ambas listas
    ft_lstclear(&list, del);      // Limpiar la lista original
    ft_lstclear(&new_list, del);  // Limpiar la nueva lista

    return 0;
}
*/
