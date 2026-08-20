/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:03:57 by belam             #+#    #+#             */
/*   Updated: 2026/08/20 20:06:04 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
This function swaps the top 2 nodes of a stack,
detaching and reattaching *prev and *next pointers
*/
// node1 and node2 are not NULL, checked to have min 2 nodes
// edge case: only 2 nodes, tail will be severed and node3 has no prev
static void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	node1 = stack->head;
	node2 = stack->head->next;
	node3 = stack->head->next->next;
	stack->head = node2;
	node2->prev = NULL;
	node2->next = node1;
	node1->prev = node2;
	node1->next = node3;
	if (node3)
		node3->prev = node1;
	else
		stack->tail = node1;
}

// check every dereference of t_node for NULL
// check for reassignment of tail node also
// edge cases: from_stack 1->0 nodes, to_stack 0->1 nodes: need to reassign tail
static void	push(t_stack *from_stack, t_stack *to_stack)
{
	t_node	*push_node;
	t_node	*from_stack_new_head;
	t_node	*to_stack_old_head;

	push_node = from_stack->head;
	from_stack_new_head = from_stack->head->next;
	to_stack_old_head = to_stack->head;
	from_stack->head = from_stack_new_head;
	if (from_stack->head)
		from_stack->head->prev = NULL;
	else
		from_stack->tail = NULL;
	to_stack->head = push_node;
	push_node->prev = NULL;
	push_node->next = to_stack_old_head;
	if (push_node->next)
		push_node->next->prev = push_node;
	else
		to_stack->tail = push_node;
	(from_stack->size)--;
	(to_stack->size)++;
}

// CHG SIZE back to 3
void	select_op(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if ((!ft_strncmp(op, "sa", 2) || !ft_strncmp(op, "ss", 2)) && stack_a->size >= 2)
		swap(stack_a);
	if ((!ft_strncmp(op, "sb", 2) || !ft_strncmp(op, "ss", 2)) && stack_b->size >= 2)
		swap(stack_b);

	if (ft_strncmp(op, "pa", 2) == 0 && stack_b->size)
		push(stack_b, stack_a);
	else if (ft_strncmp(op, "pb", 2) == 0 && stack_a->size)
		push(stack_a, stack_b);
	printf("%s\n", op);
	print_stack(stack_a, stack_b);
}
