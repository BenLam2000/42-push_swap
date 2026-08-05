/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:35:28 by belam             #+#    #+#             */
/*   Updated: 2026/08/05 17:43:12 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
This function creates a new stack node,
places data in it, then links it to NULL
next node in the linked list will simply override NULL
*/
t_node	*create_node(int data, t_node *prev)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = prev;
	new_node->next = NULL;
	return (new_node);
}

/*
Create first node and fix stack head pointing to it (to return at the end),
use another traverser pointer to build stack node by node,
create new next node -> move to next node -> create new next node -> move to next node
*/
int	input_to_stack(char **endptr, t_stack *stackptr)
{
	int		i;
	t_node	*head;
	t_node	*traverser;

	i = 0;
	head = create_node(ft_atoi_imp(*endptr, endptr), NULL);
	(*endptr)++;
	i++;
	if (!head)
		return (0);
	traverser = head;
	while (i < stackptr->size)
	{
		traverser->next = create_node(ft_atoi_imp(*endptr, endptr), traverser);
		(*endptr)++;
		if (!(traverser->next))
			return (0);
		traverser = traverser->next;
		i++;
	}
	stackptr->head = head;
	stackptr->tail = traverser;
	return (1);
}

void	print_stack(t_stack *stack)
{
	t_node	*traverser;

	printf("forwards:\n");
	if (stack->head)
	{
		traverser = stack->head;
		while (traverser)
		{
			printf("%4d\n", traverser->data);
			printf("%4s\n", " | ");
			traverser = traverser->next;
		}
	}
	printf("%4s\n", "NULL");

	printf("backwards:\n");
	if (stack->tail)
	{
		traverser = stack->tail;
		while (traverser)
		{
			printf("%4d\n", traverser->data);
			printf("%4s\n", " | ");
			traverser = traverser->prev;
		}
	}
	printf("%4s\n", "NULL");
}
