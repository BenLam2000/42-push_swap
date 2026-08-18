/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:35:28 by belam             #+#    #+#             */
/*   Updated: 2026/08/18 19:16:23 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		num;
	int		exit_code;
	t_node	*temp_node;
	char	*endptr_prev;

	while (**endptr)
	{
		// parse input num
		endptr_prev = *endptr;
		num = ft_atoi_imp(*endptr, endptr);

		// validate input
		exit_code = is_input_invalid(*endptr, endptr_prev);
		if (exit_code)
			return (exit_code);

		// prepare endptr for next parsing
		if (**endptr)
			(*endptr)++;

		// check duplicates from HEAD to current node
		if (has_duplicate(stackptr, num))
			return (5);

		// if no error, build new stack node
		temp_node = create_node(num, stackptr->tail);
		if (!(temp_node))
			return (8);
		if (stackptr->size == 0)
		{
			stackptr->head = temp_node;
			stackptr->tail = stackptr->head;
		}
		else
		{
			stackptr->tail->next = temp_node;
			stackptr->tail = stackptr->tail->next;
		}

		// increment stack size via stackptr directly
		(stackptr->size)++;
	}
	// check list size has at least 2 numbers
	if (stackptr->size < 2)
		return (6);

	// check sorted, should only be checked after complete pass of input
	if (is_sorted(stackptr))
		return (7);
	return (0);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_traverser;
	t_node	*b_traverser;

	//printf("forwards:\n");
	printf("%5s\t%5s\n", "A", "B");
	printf("-------------------\n");
	if (stack_a->head || stack_b->head)
	{
		a_traverser = stack_a->head;
		b_traverser = stack_b->head;
		while (a_traverser || b_traverser)
		{
			if (a_traverser)
			{
				printf("%5d", a_traverser->data);
				a_traverser = a_traverser->next;
			}
			else
				printf("%5s", "     ");
			printf("\t");
			if (b_traverser)
			{
				printf("%5d", b_traverser->data);
				b_traverser = b_traverser->next;
			}
			else
				printf("%5s", "     ");
			printf("\n");
		}
	}

	//printf("backwards:\n");
	//printf("%5s\t%5s\n", "A", "B");
	printf("-------------------\n");
	if (stack_a->tail || stack_b->tail)
	{
		a_traverser = stack_a->tail;
		b_traverser = stack_b->tail;
		while (a_traverser || b_traverser)
		{
			if (a_traverser)
			{
				printf("%5d", a_traverser->data);
				a_traverser = a_traverser->prev;
			}
			else
				printf("%5s", "     ");
			printf("\t");
			if (b_traverser)
			{
				printf("%5d", b_traverser->data);
				b_traverser = b_traverser->prev;
			}
			else
				printf("%5s", "     ");
			printf("\n");
		}
	}
}
