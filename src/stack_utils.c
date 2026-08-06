/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:35:28 by belam             #+#    #+#             */
/*   Updated: 2026/08/06 18:17:55 by belam            ###   ########.fr       */
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
	int		count;
	int		num;
	int		exit_code;
	t_node	*temp_node;

	count = 0;
	// validate input
	exit_code = is_input_invalid(endptr, count);
	if (exit_code)
		return (exit_code);
	while (**endptr)
	{
		// parse input num
		num = ft_atoi_imp(*endptr, endptr);
		count++;

		// validate input
		exit_code = is_input_invalid(endptr, count);
		if (exit_code)
			return (exit_code);
		if (**endptr)
		{
			(*endptr)++;
			count++;
		}

/*
		// check sorted, should only be checked after complete pass of input
		exit_code = is_sorted(stackptr);
		if (exit_code)
			return (exit_code);
*/
		// check duplicates from HEAD to current node
		if (has_duplicate(stackptr, num))
			return (5);

		// if no error, build new stack node
		temp_node = create_node(num, stackptr->tail);
		if (!(temp_node))
			return (7);
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
	return (0);
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
