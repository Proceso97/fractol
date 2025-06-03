/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:44:57 by jzarza-g          #+#    #+#             */
/*   Updated: 2024/10/23 20:11:49 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Función para imprimir el contenido del nodo
void print_content(void *content) {
    if (content) {
        printf("%d\n", *(int *)content);
    }
}

// Función principal para probar ft_lstiter
int main() {
    t_list *list = NULL; // Inicializamos la lista como vacía

    // Crear algunos nodos
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    *data1 = 10;
    *data2 = 20;
    *data3 = 30;

    // Añadir nodos a la lista
    ft_lstadd_front(&list, ft_lstnew(data1));
    ft_lstadd_front(&list, ft_lstnew(data2));
    ft_lstadd_front(&list, ft_lstnew(data3));

    // Usar ft_lstiter para imprimir el contenido de cada nodo
    printf("Contenido de la lista:\n");
    ft_lstiter(list, print_content);

    // Liberar la memoria de la lista
    ft_lstclear(&list, free);

    return 0;
}
*/
