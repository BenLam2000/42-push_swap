/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:03:04 by belam             #+#    #+#             */
/*   Updated: 2026/08/31 17:12:38 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"

/*
This function creates a new stack node,
places data in it, then links it to NULL
next node in the linked list will simply override NULL
*/
static t_node	*add_node(int data, t_node *prev)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->target = NULL;
	new_node->prev = prev;
	new_node->next = NULL;
	return (new_node);
}

/*
Create first node and fix stack head pointing to it (to return at the end),
use another traverser pointer to build stack node by node,
create new next node -> move to next node -> create new next node -> 
move to next node
*/
void	create_stack(int *num_arr, size_t len, t_stack *stack)
{
	t_node	*temp_node;

	while (stack->size < len)
	{
		temp_node = add_node(num_arr[stack->size], stack->tail);
		if (temp_node == NULL)
		{
			free_stack(stack);
			free(num_arr);
			ft_error(ERR_MALLOC);
		}
		if (stack->head == NULL)
		{
			stack->head = temp_node;
			stack->tail = stack->head;
		}
		else
		{
			stack->tail->next = temp_node;
			stack->tail = stack->tail->next;
		}
		(stack->size)++;
	}
	free(num_arr);
}

void	free_stack(t_stack *stack)
{
	t_node	*next_node;
	t_node	*prev_node;

	if (stack->head == NULL)
		return ;
	prev_node = stack->head;
	next_node = stack->head->next;
	while (prev_node)
	{
		free(prev_node);
		prev_node = next_node;
		if (next_node)
			next_node = next_node->next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
