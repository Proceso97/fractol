/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:42:44 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/10/23 20:07:43 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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

// Función principal para probar ft_lstclear
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

    *data1 = 10;
    *data2 = 20;
    *data3 = 30;

    // Añadir nodos a la lista
    ft_lstadd_front(&list, ft_lstnew(data1));
    ft_lstadd_front(&list, ft_lstnew(data2));
    ft_lstadd_front(&list, ft_lstnew(data3));

    // Imprimir contenido de la lista antes de limpiar
    printf("Contenido de la lista antes de ft_lstclear:\n");
    ft_lstiter(list, print_content);

    // Limpiar la lista
    ft_lstclear(&list, del);

    // Verificar si la lista está vacía
    if (list == NULL) {
        printf("La lista está vacía después de ft_lstclear.\n");
    } else {
        printf("La lista NO está vacía después de ft_lstclear.\n");
    }

    return 0;
}
*/
